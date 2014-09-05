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
#include "../controllers/BitInStream.hpp"
#include "../controllers/BitOutStream.hpp"
#include "../structures/Nodo.hpp"
#include "../method/Method.hpp"
#include "../method/byteMethod.hpp"
class lz77 {
public:
    lz77();
    lz77(const lz77& orig);
    void code(string name_in, string name_out, int ws);
    void code2(string name_in, string name_out, int ws);

    //void writeHuffman(BitOutStream &out, vector<string*> &code, unsigned char c);
    //void writeByte(BitOutStream &bos, unsigned char c);
    virtual ~lz77();
private:
    
};

#endif	/* LZ77_HPP */

