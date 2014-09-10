/* 
 * File:   algorithmController.cpp
 * Author: leo
 * 
 * Created on September 6, 2014, 2:37 AM
 */

#include "algorithmController.hpp"


algorithmController::algorithmController() {
    _algorithm=NULL;
}

algorithmController::algorithmController(const algorithmController& orig) {
}

algorithmController::~algorithmController() {
}

void algorithmController::setHuffman(bool compress, string input, string output) {
    //string output;
    //if(compress) output=input+".bin";
    //else output=input+".sal";
    
    _algorithm= new Huffman(input,output);
         
}

void algorithmController::setHuffmanlz77(bool compress, string input,string output, int ws) {
    //string output;
    //if(compress) output=input+".bin";
    //else output=input+".sal";
    
    _algorithm= new lzhuffman(ws,input,output);
    
}

void algorithmController::setlz77(bool compress, string input, string output, int ws) {
    //string output;
    //if(compress) output=input+".bin";
    //else output=input+".sal";
    
    _algorithm= new lz77(ws,input,output);
}



void algorithmController::decode() {
    _algorithm->decode();
}

void algorithmController::encode() {
    _algorithm->encode();
}

void algorithmController::encode_decode(bool encode){
    if(encode)
        _algorithm->encode();
    else
        _algorithm->decode();
}

