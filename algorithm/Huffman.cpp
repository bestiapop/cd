/* 
 * File:   Huffman.cpp
 * Author: leo
 * 
 * Created on September 2, 2014, 7:04 PM
 */

#include "Huffman.hpp"


#define K 256

using namespace std;

Huffman::Huffman() {
}

Huffman::Huffman(const Huffman& orig) {
}

Huffman::~Huffman() {
}


int* Huffman::empiricProbability(BitInStream &fileread, long int &length){
    int *prob= new int[K];
    char c;
    while((c=fileread.getChar())>-1){
        prob[c]++;
        length++;
        //cout<<(int)c<< c <<endl;
    }
    fileread.close();

    return prob;
}

bool comparator(Nodo* a, Nodo* b){
    return a->getFrec() > b->getFrec();
}

Nodo* Huffman::generateTree(int* frec){
    vector<Nodo*> vec= vector<Nodo*>();
    for(int i=0; i<K; i++){
        if(frec[i]>0){
            Nodo* n= new Nodo((char)i,frec[i]);
            vec.push_back(n);
        }
    }
    sort(vec.begin(),vec.end(),comparator);

    //cout<<"cant frec"<<endl;
    //for(int i=0; i<vec.size(); i++){
    //    cout<< ((Nodo *)vec[i])->getFrec()<<
    //            (char)((Nodo *)vec[i])->getChar()<<endl;
    //}
    
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


void Huffman::generateCode(Nodo *&n, vector<string*> &code, string ac){
    if(n!=NULL){
        if(n->isLeaf()){
            code[n->getChar()]=new string(ac);
            //cout<<n->getChar()<<endl;
            //cout<<ac<<endl;
        }else{  
            generateCode(n->getLeft(),code,ac+"0");//ac+"0");
            generateCode(n->getRight(),code,ac+"1");//+"1");
        }
    }

}

void Huffman::writeTree(Nodo* &root, BitOutStream &fileout){
    if(root->isLeaf()){ //hoja
        fileout.writeBit(true);//fileout<<true;
        //cout<<1;
        //fileout<<(char)root->getChar();
        char c=root->getChar();
        //cout<<c<<"(";
        fileout.writeByte(c);//fileout.put(root->getChar());
        //cout<<")";
    }else{
        fileout.writeBit(false);//fileout<<false;
        //cout<<0;
        writeTree(root->getLeft(),fileout);
        writeTree(root->getRight(),fileout);
    }
}


Nodo* Huffman::readTree(BitInStream &filein){
    bool bit;
    bit=filein.getBit();//filein>>bit;
    //cout<<bit<<endl;
    if(bit){
        char c;
        //filein>>c;
        c=filein.getChar();
        //cout<<c<<endl;
        return new Nodo(c,-1);
    }else{
        Nodo* izq= readTree(filein);
        Nodo* der= readTree(filein);
        return new Nodo('\0',-1,izq,der);
    }

}


void Huffman::code(string in_name, string out_name){
    BitInStream fileread(in_name);
    BitOutStream filewrite(out_name);
    long int length=0;
    
    vector<string*> codes= vector<string*>(256);
    for(int i=0; i<256; i++)
        codes[i]=NULL;
    
    cout<<"Calculating empiric..."<<endl;
    int* prob= empiricProbability(fileread,length);
    fileread.close();
    //cierro, luego lo abro nuevamente
    
    cout<<"Generating tree..."<<endl;
    Nodo * root= generateTree(prob);
    //root->printNodo("");
    
    
    cout<<"Generating code..."<<endl;
    generateCode(root,codes,"");
    
    //for(int i=0; i<256; i++)
    //    if(codes[i]!=NULL) cout<<dec<<i<<"__"<<*codes[i]<<endl;
    
    //descriptor para decoder
    //  LONG INT    : how many symbols contains the original file;  
    //  DECODER     : describes the tree parser, this is used for decode de file; 32 bits
    //  ENCODED FILE
    
    cout<<"Writing LONG INT"<<endl;
    filewrite.writeInt(length);
    
    cout<<"Writing tree..."<<endl;
    writeTree(root,filewrite);

    fileread.open(in_name); //second read
    
    cout<<"Compressing Body..."<<endl;
    char c;
    while((c=fileread.getChar())>-1){
        string * toParse= codes[c];
        //cout<<(int)c<< "__"<<*toParse<<endl;

        for(int i=0;i<toParse->length();i++){
            if(toParse->at(i)=='0'){
                //cout<<toParse->at(i)<<endl;
                filewrite.writeBit(false);//filewrite<<false;
                //cout<<0;
                }
            else{
                filewrite.writeBit(true);//filewrite<<true;
                //cout<<1;
            }
        }
        
    }
    
    cout<<endl<<"Finish encoding..."<<endl;
    fileread.close();
    filewrite.close();

    //delete memory
    delete [] prob;
    codes.erase(codes.begin(),codes.end());
    //delete tree
    
}

void Huffman::decode(string in_name, string out_name){
    BitInStream filein(in_name);
    BitOutStream fileout(out_name);
    long int length= filein.getInt();
    
    Nodo* root= readTree(filein);
    //root->printNodo("*");
    
    bool bit;
    for(int i=0; i<length; i++){
        Nodo* rec=root;
        while(!rec->isLeaf()){
            bit=filein.getBit();
            if(bit)
                rec=rec->getRight();
            else
                rec=rec->getLeft();       
        }
        fileout.writeByte(rec->getChar());
    }
    
    fileout.close();
    filein.close();
    //delete tree
}