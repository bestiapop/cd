/* 
 * File:   Algorithm.hpp
 * Author: leo
 *
 * Created on September 5, 2014, 7:59 PM
 */

#ifndef ALGORITHM_HPP
#define	ALGORITHM_HPP

#define K 256

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "../controllers/BitInStream.hpp"
#include "../controllers/BitOutStream.hpp"
#include "../structures/Nodo.hpp"

using namespace std;
typedef vector<string> Lista;

class Algorithm {
public:
    Algorithm();
    Algorithm(const Algorithm& orig);
    virtual void encode(BitInStream&,BitOutStream&)=0;
    virtual void decode(BitInStream&, BitOutStream&)=0;
    virtual ~Algorithm();

protected:
    int* empiricProbability(BitInStream &fileread, long int &length);
    Nodo* generateTree(int* frec);
    void generateCode(Nodo *&n, vector<string*> &code, string ac);
    void writeTree(Nodo* &root, BitOutStream &fileout);
    Nodo* readTree(BitInStream &filein);
private:

};

#endif	/* ALGORITHM_HPP */

