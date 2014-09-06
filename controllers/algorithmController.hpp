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
#include "../method/Method.hpp"
#include "../method/byteMethod.hpp"
#include "../method/huffmanMethod.hpp"

class algorithmController {
public:
    algorithmController();
    algorithmController(const algorithmController& orig);
    
    void setAlgorithm(int, string ,string);
    void setAlgorithm(Algorithm* &a);
    void encode_decode(bool encode);
    void encode();
    void decode();
    
    virtual ~algorithmController();
private:
    Algorithm * _algorithm;
    BitInStream * _bis;
    BitOutStream * _bos;
};

#endif	/* ALGORITHMCONTROLLER_HPP */

