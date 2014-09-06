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


void Huffman::encode(BitInStream &fileread, BitOutStream &filewrite){
    
    //string in_name = args[0];
    //string out_name = args[1];
    //BitInStream fileread(in_name);
    //BitOutStream filewrite(out_name);
    //BitInStream fileread;
    //BitOutStream filewrite;
    
    string in_name="z";
            
            
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
        
    cout<<"Generating code..."<<endl;
    generateCode(root,codes,"");
      
    //descriptor para decoder
    //  LONG INT    : how many symbols contains the original file;  
    //  DECODER     : describes the tree parser, this is used for decode de file; 32 bits
    //  ENCODED FILE
    
    cout<<"Writing LONG INT"<<endl;
    filewrite.writeInt(length);
    cout<<length<<endl;
    
    cout<<"Writing tree..."<<endl;
    writeTree(root,filewrite);

    fileread.open(in_name); //second read
    
    cout<<"Compressing Body..."<<endl;
    char c;
    while((c=fileread.getChar())>-1){
        string * toParse= codes[c];
        cout<<c;
        for(int i=0;i<toParse->length();i++){
            if(toParse->at(i)=='0'){
                filewrite.writeBit(false);
                }
            else{
                filewrite.writeBit(true);
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

void Huffman::decode(BitInStream &filein, BitOutStream &fileout){
    //string in_name = args[0];
    //string out_name = args[1];
    
    //BitInStream filein(in_name);
    //BitOutStream fileout(out_name);
    //BitInStream filein;
    //BitOutStream fileout;
    
    cout<<"start decoding"<<endl;
    
    long int length= filein.getInt();
    cout<<length<<endl;
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