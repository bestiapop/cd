/* 
 * File:   lzhuffman.hpp
 * Author: leo
 *
 * Created on September 6, 2014, 12:53 PM
 */

#ifndef LZHUFFMAN_HPP
#define	LZHUFFMAN_HPP

#include "Algorithm.hpp"
#include "lz77.hpp"

class lzhuffman: public lz77 {
public:
    lzhuffman();
    lzhuffman(const lzhuffman& orig);
    lzhuffman(int,string,string);
    virtual void encode();
    virtual void decode();
    virtual ~lzhuffman();
private:
    int _ws;
};

#endif	/* LZHUFFMAN_HPP */

