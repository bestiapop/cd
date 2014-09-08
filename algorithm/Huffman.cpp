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
}

void Huffman::encode(){
    
    /****************************/
    //           VAR            //
    /****************************/

    long int length=0;
    vector<string*> * codes;
    
    cout<<"Calculating empiric..."<<endl;
    int* prob= empiricProbability(length);

    //write descriptor for decoder
    decoderDescriptor(prob,codes,length,true);
    
    //
    //  Write Body
    //
    bis->open(_filein); //second read
    cout<<"Compressing Body..."<<endl;
    //setting code to bos
    BitOutHuffman *bosd = dynamic_cast<BitOutHuffman*>(bos);
    bosd->setCodes(*codes);
    
    
    char c;
    while((c=bis->getChar())>-1){
        //encodeCharHuffman(codes,c);
        bosd->writeChar(c);
    }
    
    cout<<endl<<"Finish encoding..."<<endl;
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
    //cout<<length<<endl;
    Nodo* root= readTree();
    //root->printNodo("*");
    
    bool bit;
    for(int i=0; i<length; i++){
        Nodo* rec=root;
        while(!rec->isLeaf()){
            bit=bis->getBit();
            if(bit)
                rec=rec->getRight();
            else
                rec=rec->getLeft();       
        }
        bos->writeByte(rec->getChar());
    }
    
    bos->close();
    bis->close();
    //delete tree
}