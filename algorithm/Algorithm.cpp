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
    char c;
    while((c=bis->getByte())>-1){
        prob[c]++;
        length++;       
    }
    bis->close();

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
    vector<string*> *codes= new vector<string*>(256);
    for(int i=0; i<256; i++)
        (*codes)[i]=NULL;
     
    generateCode(n,*codes,"");        
    return codes;
}


void Algorithm::writeTree(Nodo* &root){
    if(root->isLeaf()){ //hoja
        bos->writeBit(true);
        char c=root->getChar();
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
        char c;
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
    
    cout<<"Generating tree..."<<endl;
    Nodo * root= generateTree(prob);  
    
    //setting the tree to read
    BitInHuffman *bisd = dynamic_cast<BitInHuffman*>(bis);
    bisd->setTree(root);     
    
    cout<<"Generating code..."<<endl;
    codes=generateCode(root);
    
    //setting code for bos
    if(BitOutHuffman *bosd = dynamic_cast<BitOutHuffman*>(bos))           
            bosd->setCodes(codes);         
    
      
    cout<<"Writing LONG INT"<<endl;
    if (print_l) bos->writeInt(length);    
    cout<<"Writing tree..."<<endl;
    writeTree(root);
}

void Algorithm::encodeCharHuffman(vector<string*>& codes, char c) {
        string * toParse= codes[c];
        cout<<c;
        for(int i=0;i<toParse->length();i++){
            if(toParse->at(i)=='0'){
                bos->writeBit(false);
                }
            else{
                bos->writeBit(true);
            }
        }
}

