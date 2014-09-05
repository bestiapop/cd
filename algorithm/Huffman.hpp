/* 
 * File:   Huffman.hpp
 * Author: leo
 *
 * Created on September 2, 2014, 7:04 PM
 */

#ifndef HUFFMAN_HPP
#define	HUFFMAN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "../structures/Nodo.hpp"
#include"../controllers/BitInStream.hpp"
#include "../controllers/BitOutStream.hpp"


class Huffman {
public:
    Huffman();
    Huffman(const Huffman& orig);
    
    //functions
    int* empiricProbability(BitInStream &fileread, long int &length);
    Nodo* generateTree(int* frec);
    void generateCode(Nodo *&n, vector<string*> &code, string ac);
    void writeTree(Nodo* &root, BitOutStream &fileout);
    Nodo* readTree(BitInStream &filein);

    void code(string,string);
    void decode(string,string);
    
    virtual ~Huffman();
private:
    static const int K=256;
};

#endif	/* HUFFMAN_HPP */
