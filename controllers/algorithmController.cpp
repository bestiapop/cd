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

void algorithmController::setAlgorithm(int i, string input, string output) {
    _bos= new BitOutStream(output);
    _bis= new BitInStream(input);
    switch(i){
        case 1:
            _algorithm= new Huffman();
            break;
        case 2:
            _algorithm= new lz77();
            break;
        default:
            _algorithm= new lz77();
            
    }
}

void algorithmController::decode() {
    
    _algorithm->decode(*_bis,*_bos);
}

void algorithmController::encode() {
    _algorithm->encode(*_bis,*_bos);
}

void algorithmController::encode_decode(bool encode){
    if(encode)
        _algorithm->encode(*_bis,*_bos);
    else
        _algorithm->decode(*_bis,*_bos);
}

