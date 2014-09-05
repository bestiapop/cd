/* 
 * File:   BitInStream.cpp
 * Author: leo
 * 
 * Created on September 3, 2014, 4:00 AM
 */

#include "BitInStream.hpp"

BitInStream::BitInStream() {
}

void BitInStream::fillBuffer(){
    //in>>buffer;
    buffer=in.get();
    N=8;//0
}

BitInStream::BitInStream(string filein) {
    in.open(filein.c_str(),ios::binary);
    fillBuffer();
}

BitInStream::BitInStream(const BitInStream& orig) {
}

BitInStream::~BitInStream() {
    in.close();
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
/*
char BitInStream::getChar(){
    if(buffer!=-1){
    if(N==8){//buffer lleno devuelvo lo que hay ahi
        char r=buffer;
        fillBuffer();
       //cout<<"finish"<<endl;
        return r;
    }
    
    int oldN=N;
    char x=buffer;
    x= x<<(8-N); //=
    fillBuffer();
    if(buffer==-1) return -1;
    N=oldN;
    x|= (buffer >> N);
    //cout<<"finish"<<endl;
    
    //print
    for(int i=1; i<=8;i++){
        cout<<(bool)(x &(0x0100>>i));
    }
    
    return x;//(x & 0xFF);
    }
    return -1;
}
*/

char BitInStream::getChar(){
    char x=0;
    for(int i=1;i<=8;i++){
        bool c=getBit();
        x= x<<1;
        if(c) x|=0x01;
        //cout<<(bool)c;
    }
    return x;
}


void BitInStream::close(){
    in.close();
}

void BitInStream::open(string filein){
    in.open(filein.c_str(),ios::binary);
    fillBuffer();
}

bool BitInStream::valid(){
    return(buffer!=-1);
}

long int BitInStream::getInt() {
    long int x=0;
    for(int i=0; i<4;i++){
        x= x<<8;
        unsigned char a=getChar();
        //cout<<a<<endl;
        x|=(long int)a;//getChar();//8bits
        
    }
    return x;
}
