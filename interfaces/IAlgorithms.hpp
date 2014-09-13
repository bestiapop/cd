/* 
 * File:   IAlgorithms.hpp
 * Author: leo
 *
 * Created on September 13, 2014, 1:18 AM
 */

#ifndef IALGORITHMS_HPP
#define	IALGORITHMS_HPP
#include <string>
using namespace std;
class IAlgorithms {
public:
    virtual void executeHuffman(string in_file, string out_file, bool compress)= 0;
    virtual void executeLZ77(string in_file, string out_file, int ws, bool compress) = 0;
    virtual void executeHuffmanLZ77(string in_file, string out_file, int ws, bool file, bool compress) = 0; 

};

#endif	/* IALGORITHMS_HPP */

