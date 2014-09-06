/* 
 * File:   Algorithm.cpp
 * Author: leo
 * 
 * Created on September 5, 2014, 7:59 PM
 */

#include "Algorithm.hpp"

Algorithm::Algorithm() {

}

Algorithm::Algorithm(const Algorithm& orig) {

}

Algorithm::~Algorithm() {

}


int* Algorithm::empiricProbability(BitInStream &fileread, long int &length){
    int *prob= new int[K];
    char c;
    while((c=fileread.getChar())>-1){
        prob[c]++;
        length++;       
    }
    fileread.close();

    return prob;
}

bool comparator(Nodo* a, Nodo* b){
    return a->getFrec() > b->getFrec();
}

Nodo* Algorithm::generateTree(int* frec){
    vector<Nodo*> vec= vector<Nodo*>();
    for(int i=0; i<K; i++){
        if(frec[i]>0){
            Nodo* n= new Nodo((char)i,frec[i]);
            vec.push_back(n);
        }
    }
    sort(vec.begin(),vec.end(),comparator);

    while(vec.size()>1){
        int frec=vec[0]->getFrec()+vec[1]->getFrec();
        Nodo *n = new Nodo('*',frec,vec[0],vec[1]);
        vec.erase(vec.begin());
        vec.erase(vec.begin());
        vec.push_back(n);
        sort(vec.begin(),vec.end(),comparator);
    }
    return vec[0]; 
}


void Algorithm::generateCode(Nodo *&n, vector<string*> &code, string ac){
    if(n!=NULL){
        if(n->isLeaf()){
            code[n->getChar()]=new string(ac);
        }else{  
            generateCode(n->getLeft(),code,ac+"0");
            generateCode(n->getRight(),code,ac+"1");
        }
    }
}

void Algorithm::writeTree(Nodo* &root, BitOutStream &fileout){
    if(root->isLeaf()){ //hoja
        fileout.writeBit(true);
        char c=root->getChar();
        fileout.writeByte(c);
    }else{
        fileout.writeBit(false);
        writeTree(root->getLeft(),fileout);
        writeTree(root->getRight(),fileout);
    }
}


Nodo* Algorithm::readTree(BitInStream &filein){
    bool bit;
    bit=filein.getBit();
    if(bit){
        char c;
        c=filein.getChar();
        return new Nodo(c,-1);
    }else{
        Nodo* izq= readTree(filein);
        Nodo* der= readTree(filein);
        return new Nodo('\0',-1,izq,der);
    }
}