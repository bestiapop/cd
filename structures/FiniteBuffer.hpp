/* 
 * File:   FiniteBuffer.hpp
 * Author: leo
 *
 * Created on September 4, 2014, 7:44 PM
 */

#ifndef FINITEBUFFER_HPP
#define	FINITEBUFFER_HPP
#include <vector>
#include "../controllers/BitInStream.hpp"
#define ABUF 7

using namespace std;

class FiniteBuffer {
public:
    FiniteBuffer();
    FiniteBuffer(int size, BitInStream * &bis);
    FiniteBuffer(const FiniteBuffer& orig);
    char &operator [](const int index);
    char at_w(const int index);
    char at_b(const int index);
    int length_w();
    int length_b();
    
    
    void shiftbuffer(int l, BitInStream * &bis);
    
    virtual ~FiniteBuffer();
private:
    vector<char> *buffer;
    vector<char> *bufferwin;
    int size_w;
    //int current_size;
    
};

#endif	/* FINITEBUFFER_HPP */

