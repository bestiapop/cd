/* 
 * File:   huffmanlzfile.cpp
 * Author: leo
 * 
 * Created on September 12, 2014, 5:00 PM
 */

#include "huffmanlzfile.hpp"

huffmanlzfile::huffmanlzfile() {
}

huffmanlzfile::huffmanlzfile(int ws, string filein, string fileout):lz77(ws, filein, fileout) {
    bos = new BitOutHuffman(fileout);
    bis = new BitInHuffman(filein);
}

huffmanlzfile::huffmanlzfile(const huffmanlzfile& orig) {
}

huffmanlzfile::~huffmanlzfile() {
}

int* huffmanlzfile::empiricProbabilityFile(long int& length) {
    BitInStream *read = new BitInStream();
    int *prob= new int[K];
    length=0;
    int c;
    while((c=read->getByte())>-1){
        prob[c]++;
        length++;       
    }
    read->close();
    
    delete read;
    return prob;
}


void huffmanlzfile::encode() {
    long int length=0;
    vector<string*> *codes;
    int* prob = empiricProbabilityFile(length);
    Nodo * root= generateTree(prob,true);  
    BitInHuffman *bisd = dynamic_cast<BitInHuffman*>(bis);
    bisd->setTree(root);     
    codes=generateCode(root);
    
    if(BitOutHuffman *bosd = dynamic_cast<BitOutHuffman*>(bos))           
        bosd->setCodes(codes);         
    
    writeTree(root);
    bis->open(_filein);   
    lz77algorithm();
    
    delete [] prob;
    delete codes;
}

void huffmanlzfile::decode() {
    Nodo * root=readTree();
    BitInHuffman *bisd = dynamic_cast<BitInHuffman*>(bis);
    bisd->setTree(root);
    vector<string*> * codes= generateCode(root);
    BitOutHuffman *bosd = dynamic_cast<BitOutHuffman*>(bos);
    bosd->setCodes(codes);
    lz77decode();    
}
