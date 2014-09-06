/* 
 * File:   method.cpp
 * Author: leo
 * 
 * Created on September 4, 2014, 5:25 PM
 */

#include "Method.hpp"

Method::Method(BitInStream &in, BitOutStream &out):in(in),out(out){

}

bool Method::readBit() {
    return in.getBit();
}

void Method::writeBit(bool bit) {
    out.writeBit(bit);
}

void Method::close() {
    out.close();
}

void Method:: writeChar(unsigned char c){
    out.writeByte(c);
}

char Method::readChar(){
    return in.getChar();
}
