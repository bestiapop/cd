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
#include "../algorithm/huffmanlzfile.hpp"

class algorithmController {
public:
    algorithmController();
    algorithmController(const algorithmController& orig);
    
    void setHuffman(string infile, string output);
    void setHuffmanlz77(string infile, string output,int ws);
    void setlz77(string infile, string output,int ws);
    void setHuffmanLzFile(string infile, string output,int ws);
    
    void encode_decode(bool encode);
    void encode();
    void decode();
    
    virtual ~algorithmController();
private:
    Algorithm * _algorithm;
};

#endif	/* ALGORITHMCONTROLLER_HPP */

