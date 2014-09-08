/* 
 * File:   BitInHuffman.cpp
 * Author: leo
 * 
 * Created on September 8, 2014, 3:50 AM
 */

#include "BitInHuffman.hpp"

BitInHuffman::BitInHuffman() {
}

BitInHuffman::BitInHuffman(string filein):BitInStream(filein) {
}

BitInHuffman::BitInHuffman(const BitInHuffman& orig) {
}

BitInHuffman::~BitInHuffman() {
}

void BitInHuffman::setTree(Nodo *& N) {
    _root= N;
}

char BitInHuffman::getChar() {
    Nodo* rec=_root;
    bool bit;
        while(!rec->isLeaf()){
            bit=getBit();
            if(bit)
                rec=rec->getRight();
            else
                rec=rec->getLeft();       
        }
    return rec->getChar();
}
