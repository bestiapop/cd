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
#include "../controllers/BitInHuffman.hpp"
#include "../controllers/BitOutHuffman.hpp"
#include "../structures/Nodo.hpp"
#include "../structures/FiniteBuffer.hpp"

using namespace std;
typedef vector<string> Lista;

class Algorithm {
public:
    Algorithm();
    Algorithm(const Algorithm& orig);
    Algorithm(string,string);
    virtual void encode()=0;
    virtual void decode()=0;
    virtual ~Algorithm();

protected:
    int* empiricProbability(long int &length);
    Nodo* generateTree(int* frec);
    void generateCode(Nodo *&n,vector<string*> &codes, string ac);
    vector<string*> *generateCode(Nodo * &n);
    void writeTree(Nodo* &root);
    Nodo* readTree();
        
    //generateTree + generateCode + writetree ==> return de code
    void decoderDescriptor(int* &prob, vector<string*>* &code, long int length, bool print_l);
    
    void encodeCharHuffman(vector<string*> &codes, char c);
    
    BitInStream *bis;
    BitOutStream *bos;
    string _filein;
    string _fileout;
private:

};

#endif	/* ALGORITHM_HPP */

