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

void algorithmController::executeHuffman(string in_file, string out_file, bool compress) {    
    setHuffman(in_file, out_file);
    encode_decode(compress);
}

void algorithmController::executeHuffmanLZ77(string in_file, string out_file, int ws, bool file, bool compress) {
    if(!file){   
        setHuffmanlz77(in_file,out_file,ws);
        encode_decode(compress);
    }else{
        setHuffmanLzFile(in_file,out_file,ws);
        encode_decode(compress);
    }
}

void algorithmController::executeLZ77(string in_file, string out_file, int ws, bool compress) {
    setlz77(in_file,out_file,ws);
    encode_decode(compress);   
}
