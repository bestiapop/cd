/* 
 * File:   BitOutStream.cpp
 * Author: leo
 * 
 * Created on September 2, 2014, 11:34 PM
 */

#include "BitOutStream.hpp"


BitOutStream::BitOutStream() {
}

BitOutStream::BitOutStream(string fileout){
    out.open(fileout.c_str(), ios::binary);
    N=0;
    buffer=0;
}


BitOutStream::BitOutStream(const BitOutStream& orig) {
}

BitOutStream::~BitOutStream() {
    out.flush();
    out.close();
}

void BitOutStream::close(){
    //out.flush();
    out.close();
}

void BitOutStream::clearBuffer(){
    if(N==0)return;
    if(N>0) buffer << N;//(8-N);
    //imprimo
    //out<<buffer;
    out.put(buffer);
    N=0;
    buffer=0;
}

void BitOutStream::writeBit(bool bit){
    //buffer |= (bit ? 1 : 0) << (8-N); //okkk!?
    cout<<bit;
    
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

void BitOutStream::writeInt(long int x) {
    writeByte((x>>24) & 0xFF);
    //cout<<endl;
    writeByte((x>>16) & 0xFF);
    //cout<<endl;
    writeByte((x>>8) & 0xFF);
   // cout<<endl;
    writeByte(x & 0xFF);

}
