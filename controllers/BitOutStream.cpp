/* 
 * File:   BitOutStream.cpp
 * Author: leo
 * 
 * Created on September 2, 2014, 11:34 PM
 */

#include "BitOutStream.hpp"


BitOutStream::BitOutStream(){
    //out =&cout;
}

BitOutStream::BitOutStream(string fileout){
    out.open(fileout.c_str(), ios::binary);
    N=0;
    buffer=0;
    size=0;
}


BitOutStream::BitOutStream(const BitOutStream& orig) {
}

BitOutStream::~BitOutStream() {
    //out.flush();
    clearBuffer();
    out.close();
}

void BitOutStream::close(){
    //out.flush();
    //if(ofstream * o= dynamic_cast<ofstream *>(out)){
    //    o->close();
    //}
    clearBuffer();
    out.close();
}

void BitOutStream::clearBuffer(){
    if(N==0)return;
    if(N>0)  buffer= buffer << (8-N);//N;//(8-N);
    //imprimo
    //out<<buffer;
    out.put(buffer);
    N=0;
    buffer=0;
    ++size;
}

void BitOutStream::writeBit(bool bit){
    //buffer |= (bit ? 1 : 0) << (8-N); //okkk!?
    //cout<<bit;
    
    buffer=buffer<<1; //shift 1
    if(bit) buffer|= 0x01; //add last bit 1
    
    //if(bit) buffer|=0x08;
    //buffer << 0x01;
    //if (bit) buffer|= 0x00;
    N++;
    //cout<<(int)buffer<<endl;
    if(N==8){
        clearBuffer();
        N=0;
        buffer=0;
    }
    
}

unsigned char BitOutStream::getBuffer(){
    return buffer;
}


void BitOutStream::open(string fileout) {
   out.open(fileout.c_str(),ios::binary);
}

void BitOutStream::writeByte(unsigned char byte){
    for(int i=1; i<=8;i++){
        writeBit(byte &(0x0100>>i));
       // cout<<(bool)(byte &(0x0100>>i));
    }
}

void BitOutStream::writeChar(unsigned char byte){
    writeByte(byte);
}

void BitOutStream::writeInt(long int x) {
    writeByte((x>>24) & 0xFF);
    writeByte((x>>16) & 0xFF);
    writeByte((x>>8) & 0xFF);
    writeByte(x & 0xFF);
}

void BitOutStream::writeLogInt(long int x) {
    //include unary notation
    long int l=ceil(log2(x+1));
    long int lx=ceil(log2(l+1));
    //print lx-1 zeros
    for(int i=0; i<lx-1;i++){
        writeBit(false);
    }
    //end bit
    writeBit(true);
    //write l length
    //cout<<lx<<endl;
    for(int i=1;i<=lx;i++){
        bool bit= l & (0x01<<(lx-i));
        writeBit(bit);
    }
    //cout<<l<<endl;
    for(int i=1; i<=l; i++){
        bool bit= x & (0x01<<(l-i));
        writeBit(bit);
    }
    
}

void BitOutStream::writeIntWS(long int ws, long int x) {
    //write x in log ws bits
    //precondition x < 2^ws
    long int l=ceil(log2(ws));
    for(int i=1; i<=l; i++){
        bool bit= x & (0x01<<(l-i));
        writeBit(bit);
    }   
}

unsigned long int BitOutStream::getSize() {
    return size;
}
