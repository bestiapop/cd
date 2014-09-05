/* 
 * File:   FiniteBuffer.hpp
 * Author: leo
 *
 * Created on September 4, 2014, 7:44 PM
 */

#ifndef FINITEBUFFER_HPP
#define	FINITEBUFFER_HPP
#include <vector>
using namespace std;

class FiniteBuffer {
public:
    FiniteBuffer();
    FiniteBuffer(int size);
    FiniteBuffer(const FiniteBuffer& orig);
    void push(char c);
    char &operator [](const int index);
    char at(const int index);
    int length();
    void wrap();
    
    virtual ~FiniteBuffer();
private:
    vector<char> buffer;
    int size;
    int current_size;
    
};

#endif	/* FINITEBUFFER_HPP */

