/* 
 * File:   Nodo.hpp
 * Author: leo
 *
 * Created on September 2, 2014, 6:53 PM
 */

#ifndef NODO_HPP
#define	NODO_HPP

#include <string>
using namespace std;
class Nodo {
public:
    Nodo();
    Nodo(int c, int frec);
    Nodo(const Nodo& orig);
    Nodo(int c, int frec, Nodo * &izq, Nodo* &der);
            
    //functions
    Nodo* &getRight();
    Nodo* &getLeft();
    int getFrec();
    char getChar();
    void printNodo(string tab);
    bool isLeaf();

    bool operator < (const Nodo &nodo) const;
    
    virtual ~Nodo();
private:
    char c;
    int frec;
    Nodo *left;
    Nodo *right;
};

#endif	/* NODO_HPP */

