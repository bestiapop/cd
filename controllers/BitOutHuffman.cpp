/* 
 * File:   BitOutHuffman.cpp
 * Author: leo
 * 
 * Created on September 6, 2014, 9:44 PM
 */

#include "BitOutHuffman.hpp"

BitOutHuffman::BitOutHuffman() {
}
BitOutHuffman::BitOutHuffman(string fileout):BitOutStream(fileout){

}

BitOutHuffman::BitOutHuffman(const BitOutHuffman& orig) {
}

BitOutHuffman::~BitOutHuffman() {
}

void BitOutHuffman::writeChar(unsigned char c) {

        string * toParse= (*_codes)[c];
        cout<<c;
        for(int i=0;i<toParse->length();i++){
            if(toParse->at(i)=='0'){
                writeBit(false);
                }
            else{
                writeBit(true);
            }
        }
}

void BitOutHuffman::setCodes(vector<string*>* & codes) {
        _codes= codes;  
}