/* 
 * File:   BitOutStream.hpp
 * Author: leo
 *
 * Created on September 2, 2014, 11:34 PM
 */

#ifndef BITOUTSTREAM_HPP
#define	BITOUTSTREAM_HPP

#include <ostream>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class BitOutStream {
public:
    BitOutStream();
    BitOutStream(string fileout);
    BitOutStream(const BitOutStream& orig);
    virtual ~BitOutStream();
    
    //functions
    void clearBuffer();
    void writeBit(bool bit);
    void writeByte(unsigned char byte);
    //int getN();
    unsigned char getBuffer();
    void writeInt(long int x);
    
    void open(string fileout);
    void close();
    
    
private:
    ofstream out;
    int N;
    unsigned char buffer;
};

#endif	/* BITOUTSTREAM_HPP */

