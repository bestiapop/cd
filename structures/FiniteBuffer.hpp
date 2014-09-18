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
#define ABUF 4096 //4kb

using namespace std;

class FiniteBuffer {
public:
    FiniteBuffer();
    FiniteBuffer(int size, BitInStream * &bis);
    FiniteBuffer(const FiniteBuffer& orig);
    int &operator [](const int index);
    int at_w(const int index);
    int at_b(const int index);
    int length_w();
    int length_b();
    bool push(BitInStream * &bis);
    
    void shiftbuffer(int l, BitInStream * &bis);
    
    virtual ~FiniteBuffer();
private:
    vector<int> *buffer;
    vector<int> *bufferwin;
    int size_w;    
};

#endif	/* FINITEBUFFER_HPP */

