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
    delete _algorithm;
}

void algorithmController::setHuffman(string input, string output) {
    _algorithm= new Huffman(input,output); 
}

void algorithmController::setHuffmanlz77(string input,string output, int ws) {
    _algorithm= new lzhuffman(ws,input,output);   
}

void algorithmController::setlz77(string input, string output, int ws) {
    _algorithm= new lz77(ws,input,output);
}

void algorithmController::setHuffmanLzFile(string infile, string output, int ws) {
    _algorithm = new huffmanlzfile(ws, infile, output);
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

