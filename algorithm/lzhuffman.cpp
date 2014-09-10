/* 
 * File:   lzhuffman.cpp
 * Author: leo
 * 
 * Created on September 6, 2014, 12:53 PM
 */

#include "lzhuffman.hpp"

lzhuffman::lzhuffman() {
}

lzhuffman::lzhuffman(const lzhuffman& orig) {
}

lzhuffman::~lzhuffman() {
}

lzhuffman::lzhuffman(int ws, string filein, string fileout):lz77(ws,filein,fileout) {
   // _ws=ws;
    bos= new BitOutHuffman(fileout);
    bis= new BitInHuffman(filein);
}

void lzhuffman::decode() {
    //readtree & generate code
    Nodo * root=readTree();
    BitInHuffman *bisd = dynamic_cast<BitInHuffman*>(bis);
    bisd->setTree(root);
    vector<string*> * codes= generateCode(root);
    //setting de code into bos
    BitOutHuffman *bosd = dynamic_cast<BitOutHuffman*>(bos);
    bosd->setCodes(codes);
    //decode
    lz77decode();
}

void lzhuffman::encode() {

    long int length=0;
    vector<string*> *codes;

    int* prob;//= empiricProbability(length);
    decoderDescriptor(prob,codes,length,false);
    
    bis->open(_filein); //second read
    cout<<"Compressing Body..."<<endl;
    
    //BitOutHuffman *bosd = dynamic_cast<BitOutHuffman*>(bos);
    //bosd->setCodes(codes);
    
    lz77algorithm();
    
    delete [] prob;
    delete codes;
    
}
