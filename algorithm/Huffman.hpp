/* 
 * File:   Huffman.hpp
 * Author: leo
 *
 * Created on September 2, 2014, 7:04 PM
 */

#ifndef HUFFMAN_HPP
#define	HUFFMAN_HPP

#include "Algorithm.hpp"


class Huffman: public Algorithm{
public:
    Huffman();
    Huffman(const Huffman& orig);
    
    virtual void encode(BitInStream &, BitOutStream &);
    virtual void decode(BitInStream &, BitOutStream &);
    
    virtual ~Huffman();
};

#endif	/* HUFFMAN_HPP */
