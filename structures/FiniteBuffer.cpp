/* 
 * File:   FiniteBuffer.cpp
 * Author: leo
 * 
 * Created on September 4, 2014, 7:44 PM
 */

#include "FiniteBuffer.hpp"

FiniteBuffer::FiniteBuffer() {
}

FiniteBuffer::FiniteBuffer(const FiniteBuffer& orig) {
}

FiniteBuffer::~FiniteBuffer() {
}

FiniteBuffer::FiniteBuffer(int size){
    buffer= vector<char>();
    this->size=size;
    this->current_size=0;
}


char& FiniteBuffer::operator [](const int index) {
    return buffer[index];
}


void FiniteBuffer::push(char c) {
        buffer.push_back(c);
        current_size++;
}

void FiniteBuffer::wrap() {
    while(buffer.size()>size){
        buffer.erase(buffer.begin());
    }
    //current_size=size;
}

char FiniteBuffer::at(const int index) {
    return buffer[index];
}

int FiniteBuffer::length() {
    return current_size;
}
