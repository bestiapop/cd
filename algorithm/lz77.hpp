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
#include "../structures/Nodo.hpp"
#include "../method/Method.hpp"
#include "../method/byteMethod.hpp"
#include "../structures/FiniteBuffer.hpp"
#include "../algorithm/Algorithm.hpp"

class lz77: public Algorithm{
public:
    lz77();
    lz77(const lz77& orig);
    lz77(int ws);
    
    virtual void encode(BitInStream &bis, BitOutStream &bos);
    virtual void decode(BitInStream &bis, BitOutStream &bos);
    void code2(string name_in, string name_out, int ws);

    //void writeHuffman(BitOutStream &out, vector<string*> &code, unsigned char c);
    //void writeByte(BitOutStream &bos, unsigned char c);
    virtual ~lz77();
private:
    int ws;
};

#endif	/* LZ77_HPP */

