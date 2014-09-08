/* 
 * File:   BitInStream.cpp
 * Author: leo
 * 
 * Created on September 3, 2014, 4:00 AM
 */

#include "BitInStream.hpp"

BitInStream::BitInStream() {
    in= &cin;
    fillBuffer();
}

void BitInStream::fillBuffer(){
    //in>>buffer;
    buffer=in->get();
    N=8;//0
}

BitInStream::BitInStream(string filein) {
    in= new ifstream(filein.c_str(),ios::binary);//in.open(filein.c_str(),ios::binary);
    fillBuffer();
}

BitInStream::BitInStream(const BitInStream& orig) {
}

BitInStream::~BitInStream() {
    //in.close();
  
}



bool BitInStream::getBit(){
    N--;//++
    bool b= buffer & (0x0100>>(8-N));//(0x0100>>N);//(1<<(8-N));
    if(N==0){
        fillBuffer();
        //N=8;
    }
    return b;
}


char BitInStream::getByte(){
    char x=0;
    for(int i=1;i<=8;i++){
        bool c=getBit();
        x= x<<1;
        if(c) x|=0x01;
    }
    return x;
}


void BitInStream::close(){
    if(ofstream * of = dynamic_cast<ofstream *>(in)){
        of->close();
    }
}

void BitInStream::open(string filein){
    
    in= new ifstream(filein.c_str(), ios::binary);//.open(filein.c_str(),ios::binary);
    fillBuffer();
}

bool BitInStream::valid(){
    return(buffer!=-1);
}

long int BitInStream::getInt() {
    long int x=0;
    for(int i=0; i<4;i++){
        x= x<<8;
        unsigned char a=getByte();
        x|=(long int)a;
        
    }
    return x;
}

char BitInStream::getChar() {
    getByte();
}
