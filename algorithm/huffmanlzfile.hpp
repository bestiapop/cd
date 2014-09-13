/* 
 * File:   huffmanlzfile.hpp
 * Author: leo
 *
 * Created on September 12, 2014, 5:00 PM
 */

#ifndef HUFFMANLZFILE_HPP
#define	HUFFMANLZFILE_HPP

#include "lz77.hpp"
#include <string>

class huffmanlzfile: public lz77{
public:
    huffmanlzfile();
    huffmanlzfile(int ws, string filein, string fileout);
    huffmanlzfile(const huffmanlzfile& orig);
    int * empiricProbabilityFile(long int &length);
    virtual void encode();
    virtual void decode();
    virtual ~huffmanlzfile();
private:

};

#endif	/* HUFFMANLZFILE_HPP */

