/* 
 * File:   Huffman.hpp
 * Author: leo
 *
 * Created on September 2, 2014, 7:04 PM
 */

#ifndef HUFFMAN_HPP
#define	HUFFMAN_HPP

#include "Algorithm.hpp"
#include "../controllers/BitOutHuffman.hpp"

class Huffman: public Algorithm{
public:
    Huffman();
    Huffman(const Huffman& orig);
    Huffman(string, string);
    
    virtual void encode();
    virtual void decode();
    
    virtual ~Huffman();
private:

};

#endif	/* HUFFMAN_HPP */
