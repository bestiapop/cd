/* 
 * File:   byteMethod.cpp
 * Author: leo
 * 
 * Created on September 4, 2014, 5:31 PM
 */

#include "byteMethod.hpp"



byteMethod::byteMethod(BitInStream &in, BitOutStream &out):Method(in,out) {

}



byteMethod::~byteMethod() {
}

void byteMethod:: writeChar(unsigned char c){
    out.writeByte(c);
}

char byteMethod::readChar(){
    return in.getChar();
}