/* 
 * File:   BitOutHuffman.hpp
 * Author: leo
 *
 * Created on September 6, 2014, 9:44 PM
 */

#ifndef BITOUTHUFFMAN_HPP
#define	BITOUTHUFFMAN_HPP

#include "BitOutStream.hpp"


class BitOutHuffman: public BitOutStream{
public:
    BitOutHuffman();
    BitOutHuffman(string fileout);
    BitOutHuffman(const BitOutHuffman& orig);
    
    virtual void writeChar(unsigned char c);
    void setCodes(vector<string*>& codes);
    
    virtual ~BitOutHuffman();
private:
    vector<string *> *_codes;
};

#endif	/* BITOUTHUFFMAN_HPP */

