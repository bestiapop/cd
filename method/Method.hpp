/* 
 * File:   method.hpp
 * Author: leo
 *
 * Created on September 4, 2014, 5:25 PM
 */

#ifndef METHOD_HPP
#define	METHOD_HPP

#include "../controllers/BitInStream.hpp"
#include "../controllers/BitOutStream.hpp"

class Method {
public:
    Method(BitInStream &in, BitOutStream &out);
    virtual void writeChar(unsigned char)=0;
    virtual char readChar()=0;
    void close();
    void writeBit(bool bit);
    bool readBit();
    
    //method();
    //method(const method& orig);
    //virtual ~method();
protected:
    BitInStream &in;
    BitOutStream &out;
};

#endif	/* METHOD_HPP */

