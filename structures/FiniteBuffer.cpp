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
    //buffer= vector<char>();
    buffer = new vector<char>();
    bufferwin= new vector<char>();
    this->size_w=size;
    //this->current_size=0;
    int aux=ABUF;
    char c;
    while(aux>0 && (c=bis->getChar())>-1){
        buffer->push_back(c);
        //cout<<c;
        aux--;
    }
    //cout<<"en buffer: "<<buffer->size()<<endl;
    //cout<<"en bufferw: "<<bufferwin->size()<<endl;
}


char& FiniteBuffer::operator [](const int index) {
    return (*buffer)[index];
}




char FiniteBuffer::at_w(const int index) {
    return (*bufferwin)[index];
}

char FiniteBuffer::at_b(const int index) {
    return (*buffer)[index];
}


void FiniteBuffer::shiftbuffer(int l, BitInStream* &bis) {
    int max=buffer->size();
    for(int i=0;i<max && i<l;i++){
        char c=buffer->at(0);
        buffer->erase(buffer->begin());
        if(bufferwin->size()==size_w){
            bufferwin->erase(bufferwin->begin());
            bufferwin->push_back(c);
        
        }else
            bufferwin->push_back(c);
        
        
    }
    //lleno el lookaside buffer
    char c;
    max= min(l,ABUF);
    while( max>0 && (c=bis->getChar())>-1){
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



