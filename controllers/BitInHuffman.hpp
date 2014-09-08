/* 
 * File:   BitInHuffman.hpp
 * Author: leo
 *
 * Created on September 8, 2014, 3:50 AM
 */

#ifndef BITINHUFFMAN_HPP
#define	BITINHUFFMAN_HPP

#include "BitInStream.hpp"
#include <string>
#include "../structures/Nodo.hpp"

class BitInHuffman:public BitInStream {
public:
    BitInHuffman();
    BitInHuffman(const BitInHuffman& orig);
    BitInHuffman(string fileout);
    
    virtual char getChar();
    void setTree(Nodo * &N);
    
    virtual ~BitInHuffman();
private:
    Nodo * _root;
};

#endif	/* BITINHUFFMAN_HPP */

