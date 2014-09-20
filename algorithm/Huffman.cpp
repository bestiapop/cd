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
    
    //print descriptor size
    long unsigned int file_size;
    if(Utils::instance()->getDebugMode()){
        file_size= bos->getSize();
        cout<<"D "<<file_size<<endl;
    }
    
    bis->open(_filein); //second read
    while((c=bis->getByte())>-1)
        bos->writeChar((unsigned char)c);
    
    bis->close();
    bos->close();
    
    if(Utils::instance()->getDebugMode()){
    long unsigned int final_size = bos->getSize();
    cout<<"C "<<final_size - file_size<<endl;
    cout<<"F "<<final_size<<endl;
    } 
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
        bos->writeByte(bis->getChar());
    }
    
    bos->close();
    bis->close();
    //delete tree
}