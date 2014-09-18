/* 
 * File:   BitInStream.cpp
 * Author: leo
 * 
 * Created on September 3, 2014, 4:00 AM
 */

#include "BitInStream.hpp"
#include <math.h>
BitInStream::BitInStream() {
    in= &cin;
    fillBuffer();
}

void BitInStream::fillBuffer(){
    //in>>buffer;
    buffer=in->get();
   //cout<<buffer<<endl;
    N=8;//0
}

BitInStream::BitInStream(string filein) {
    cout<<filein<<endl;
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


int BitInStream::getByte(){
    int x=0;
    if(buffer!=-1){
    for(int i=1;i<=8;i++){
        bool c=getBit();
        //cout<<i<<"_"<<c<<"|";
        x= x<<1;
        if(c) x|=0x01;
    }
    return x;
    }else{
        return -1;
    }   
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

long int BitInStream::fileLength() {
    streampos begin, end;
    begin= in->tellg();
    in->seekg(0, ios::end);
    end= in->tellg();
    in->clear();
    in->seekg(begin);
    return end-begin;
    
}

long int BitInStream::getLogInt() {
    bool bit;
    int n=0;
    long int ret=0;
    long int l=0;
    while(!getBit() && valid())
        n++;
    //caso borde
    if(!valid()){
        return 0;
    }
    
    if(n>0){ //zero then no read
    int lx = n+1;
    
    for(int i=0; i<lx;i++){
        bit=getBit();
        l= l<<1;
        if(bit) l|=0x01;
    }
    
    for(int i=0; i<l; i++){
        bit=getBit();
        ret= ret<<1;
        if(bit) ret|=0x01;
    }
        return ret;
    }else{
        return 1;
    }
}

long int BitInStream::getInt(int ws) {
    //reads int sizeof log2 ws
    int l=ceil(log2(ws));
    bool bit;
    long int ret=0;
    for(int i=0; i<l; i++){
        bit=getBit();
        ret= ret<<1;
        if(bit) ret|=0x01;
    }    
    return ret;
}
