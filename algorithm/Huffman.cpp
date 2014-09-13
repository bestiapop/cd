/* 
 * File:   Huffman.cpp
 * Author: leo
 * 
 * Created on September 2, 2014, 7:04 PM
 */

#include "Huffman.hpp"


#define K 512

using namespace std;

Huffman::Huffman() {
}

Huffman::Huffman(const Huffman& orig) {
}

Huffman::~Huffman() {
}

Huffman::Huffman(string filein, string fileout): Algorithm(filein,fileout){
    bos= new BitOutHuffman(fileout);
    bis= new BitInHuffman(filein);
}

void Huffman::encode(){
    
    /****************************/
    //           VAR            //
    /****************************/

    long int length=0;
    vector<string*> * codes;
    int c;
    int* prob;
    
    //cout<<"Calculating empiric..."<<endl;

    //write descriptor for decoder
    decoderDescriptor(prob,codes,length,true);
    bis->open(_filein); //second read
    //cout<<"Compressing Body..."<<endl;

    while((c=bis->getByte())>-1)
        bos->writeChar((unsigned char)c);
    
    
    //cout<<endl<<"Finish encoding..."<<endl;
    bis->close();
    bos->close();

    //delete memory
    delete [] prob;
    //codes.erase(codes.begin(),codes.end());
    delete codes;
    //delete tree  
}

void Huffman::decode(){

    long int length= bis->getInt();
    Nodo* root= readTree();
    
    BitInHuffman *bisd = dynamic_cast<BitInHuffman*>(bis);
    bisd->setTree(root);

    
    bool bit;
    for(int i=0; i<length; i++){
       // bos->writeByte(rec->getChar());
        bos->writeByte(bis->getChar());
    }
    
    bos->close();
    bis->close();
    //delete tree
}