/* 
 * File:   BitInStream.hpp
 * Author: leo
 *
 * Created on September 3, 2014, 4:00 AM
 */

#ifndef BITINSTREAM_HPP
#define	BITINSTREAM_HPP
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class BitInStream {
public:
    BitInStream();
    BitInStream(string filein);
    BitInStream(const BitInStream& orig);
    
    //functions
    void fillBuffer();
    bool getBit();
    int getByte();
    //for huffman code
    virtual char getChar();
    long int getInt();
    long int getLogInt();
    long int getInt(int ws);
    void close();
    void open(string filein);
    bool valid();
    long int fileLength();
    
    virtual ~BitInStream();
    
private:
    istream *in;
    int buffer;
    int N;

};

#endif	/* BITINSTREAM_HPP */

