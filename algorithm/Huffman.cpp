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
        cout<<file_size<<endl;
    }
    
    bis->open(_filein); //second read
    while((c=bis->getByte())>-1)
        bos->writeChar((unsigned char)c);
    
    bis->close();
    bos->close();
    
    if(Utils::instance()->getDebugMode()){
    long unsigned int final_size = bos->getSize();
    cout<<final_size - file_size<<endl;
    cout<<final_size<<endl;
    } 
    
    double total=0;
    double entropia=0;
    double entropiacaso=0;

    for(int i=0; i<K; i++){
        total+= prob[i];
    }
    for(int i=0; i<K; i++){
        if(prob[i]>0){
        double pa= prob[i]/total;
        entropia+= pa * log2(1/pa);
        //cout<<log2(1/pa)<<endl;
        entropiacaso+= pa * (*(*codes)[i]).size();
        }
    }
    if(Utils::instance()->getDebugMode()){
        cout<<"Entropia teorica: "<<entropia<<endl;
        cout<<"Tasa entropia: "<<entropia*length<<endl;
        cout<<"Entropia obtenida: "<<entropiacaso<<endl;
        //cout<<"Tasa entropia: "<<entropiacaso*length<<endl;

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