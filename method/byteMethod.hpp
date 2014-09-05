/* 
 * File:   byteMethod.hpp
 * Author: leo
 *
 * Created on September 4, 2014, 5:30 PM
 */

#ifndef BYTEMETHOD_HPP
#define	BYTEMETHOD_HPP
#include "Method.hpp"

class byteMethod: public Method {
public:
    byteMethod();
    byteMethod(BitInStream &in, BitOutStream &out);
    byteMethod(const byteMethod& orig);
    virtual void writeChar(unsigned char c);
    virtual char readChar();
    virtual ~byteMethod();
    
private:

};

#endif	/* BYTEMETHOD_HPP */

