/* 
 * File:   lz77.hpp
 * Author: leo
 *
 * Created on September 4, 2014, 3:08 AM
 */

#ifndef LZ77_HPP
#define	LZ77_HPP

#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../controllers/BitInStream.hpp"
#include "../controllers/BitOutStream.hpp"
#include "../controllers/BitOutHuffman.hpp"
#include "../structures/Nodo.hpp"
#include "../structures/FiniteBuffer.hpp"
#include "../algorithm/Algorithm.hpp"
#include "../controllers/Utils.hpp"

class lz77: public Algorithm{
public:
    lz77();
    lz77(const lz77& orig);
    lz77(int ws,string,string);
    
    void lz77algorithm();
    void lz77decode();
    virtual void encode();
    virtual void decode();

    virtual ~lz77();
private:
    int ws;
};

#endif	/* LZ77_HPP */

