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
    delete bis;
    delete bos;
}

Algorithm::Algorithm(string filein, string fileout){//:bis(filein), bos(fileout) {
    _filein=filein;
    _fileout=fileout;
}


int* Algorithm::empiricProbability(long int &length){
    int *prob= new int[K];
    length=0;
    int c;
    while((c=bis->getByte())>-1){
        //cout<<c<<endl;
        prob[c]++;
        length++;       
    }
    bis->close();

    return prob;
}

bool comparator(Nodo* a, Nodo* b){
    return a->getFrec() < b->getFrec();
}

Nodo* Algorithm::generateTree(int* frec, bool zeros){
    vector<Nodo*> vec= vector<Nodo*>();
    int F=0;
    if(zeros) F=-1; 
    for(int i=0; i<K; i++){
        if(frec[i]>F){
            Nodo* n= new Nodo((unsigned char)i,frec[i]);
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


void Algorithm::generateCode(Nodo *&n, vector<string*>&codes, string ac){

    if(n!=NULL){
        if(n->isLeaf()){
            codes[n->getChar()]=new string(ac);
        }else{  
            generateCode(n->getLeft(),codes,ac+"0");
            generateCode(n->getRight(),codes,ac+"1");
        }
    }
}

//wrapper
vector<string*>* Algorithm::generateCode(Nodo*& n) {
    vector<string*> *codes= new vector<string*>(K);
    for(int i=0; i<K; i++)
        (*codes)[i]=NULL;
     
    generateCode(n,*codes,"");        
    return codes;
}


void Algorithm::writeTree(Nodo* &root){
    if(root->isLeaf()){ //hoja
        bos->writeBit(true);
        unsigned char c=root->getChar();
        bos->writeByte(c);
    }else{
        bos->writeBit(false);
        writeTree(root->getLeft());
        writeTree(root->getRight());
    }
}


Nodo* Algorithm::readTree(){
    bool bit;
    bit=bis->getBit();
    if(bit){
        unsigned char c;
        c=bis->getByte();
        return new Nodo(c,-1);
    }else{
        Nodo* izq= readTree();
        Nodo* der= readTree();
        return new Nodo('\0',-1,izq,der);
    }
}

void Algorithm::decoderDescriptor(int*& prob, vector<string*> * &codes, long int length, bool print_l) {
    //descriptor para decoder
    //  LONG INT    : how many symbols contains the original file;  
    //  DECODER     : describes the tree parser, this is used for decode de file; 32 bits
    //  ENCODED FILE    
    prob= empiricProbability(length);
    Nodo * root= generateTree(prob,false);  
    //setting the tree to read
    BitInHuffman *bisd = dynamic_cast<BitInHuffman*>(bis);
    bisd->setTree(root);     
    
    codes=generateCode(root);
    
    //setting code for bos
    if(BitOutHuffman *bosd = dynamic_cast<BitOutHuffman*>(bos))           
            bosd->setCodes(codes);         
    
    if (print_l) bos->writeInt(length);  
    writeTree(root);
}

