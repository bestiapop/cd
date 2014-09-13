/* 
 * File:   FiniteBuffer.cpp
 * Author: leo
 * 
 * Created on September 4, 2014, 7:44 PM
 */

#include "FiniteBuffer.hpp"

FiniteBuffer::FiniteBuffer(){
}

FiniteBuffer::FiniteBuffer(const FiniteBuffer& orig){
    buffer=NULL;
}

FiniteBuffer::~FiniteBuffer() {
    if (buffer!=NULL) delete buffer;
}

FiniteBuffer::FiniteBuffer(int size, BitInStream * &bis){
    buffer = new vector<int>();
    bufferwin= new vector<int>();
    this->size_w=size;
    int aux=ABUF;
    int c;
    
    while(aux>0 && (c=bis->getByte())>-1){
        buffer->push_back(c);
        aux--;
    }

}


int& FiniteBuffer::operator [](const int index) {
    return (*buffer)[index];
}




int FiniteBuffer::at_w(const int index) {
    return (*bufferwin)[index];
}

int FiniteBuffer::at_b(const int index) {
    return (*buffer)[index];
}


void FiniteBuffer::shiftbuffer(int l, BitInStream* &bis) {
    int max=buffer->size();
    for(int i=0;i<max && i<l;i++){
        int c=buffer->at(0);
        buffer->erase(buffer->begin());
        if(bufferwin->size()==size_w){
            bufferwin->erase(bufferwin->begin());
            bufferwin->push_back(c);
        
        }else
            bufferwin->push_back(c);
        
        
    }
    //lleno el lookaside buffer
    int c;
    max= min(l,ABUF);
    while( max>0 && (c=bis->getByte())>-1){
        buffer->push_back(c);
        max--;
    }
}

int FiniteBuffer::length_b() {
    return buffer->size();
}

int FiniteBuffer::length_w() {
    return bufferwin->size();
}



