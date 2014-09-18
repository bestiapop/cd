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
    
    //write descriptor for decoder
    decoderDescriptor(prob,codes,length,true);
    bis->open(_filein); //second read
    while((c=bis->getByte())>-1)
        bos->writeChar((unsigned char)c);
    
    bis->close();
    bos->close();
    
    //delete allocated memory
    delete [] prob;
    delete codes;
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