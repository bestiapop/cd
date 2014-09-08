/* 
 * File:   algorithmController.hpp
 * Author: leo
 *
 * Created on September 6, 2014, 2:37 AM
 */

#ifndef ALGORITHMCONTROLLER_HPP
#define	ALGORITHMCONTROLLER_HPP

#include "../algorithm/Algorithm.hpp"
#include "../algorithm/Huffman.hpp"
#include "../algorithm/lz77.hpp"
#include "../algorithm/lzhuffman.hpp"

class algorithmController {
public:
    algorithmController();
    algorithmController(const algorithmController& orig);
    
    void setHuffman(bool compress,string infile);
    void setHuffmanlz77(bool compress,string infile,int ws);
    void setlz77(bool compress,string infile,int ws);
    
    void encode_decode(bool encode);
    void encode();
    void decode();
    
    virtual ~algorithmController();
private:
    Algorithm * _algorithm;
};

#endif	/* ALGORITHMCONTROLLER_HPP */
