/* 
 * File:   Nodo.cpp
 * Author: leo
 * 
 * Created on September 2, 2014, 6:54 PM
 */

#include "Nodo.hpp"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

Nodo::Nodo() {
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

Nodo::Nodo(int c, int frec){
    this->c=c;
    this->frec=frec;
    this->right=NULL;
    this->left=NULL;
}

Nodo::Nodo(int c, int frec, Nodo * &izq, Nodo* &der){
    this->c=c;
    this->frec=frec;
    this->right=der;
    this->left=izq;
}

Nodo* &Nodo::getRight(){
    return right;
};
Nodo* &Nodo::getLeft(){
    return left;
}
int Nodo::getFrec(){
    return frec;
}
unsigned char Nodo::getChar(){
    return c;
}

bool Nodo::operator < (const Nodo &nodo) const{
    return (this->frec < nodo.frec); //for sort
}

bool Nodo::isLeaf(){
    return (right==NULL && left==NULL);
}

void Nodo::printNodo(string tab){
        cout<<tab<<this->c<<endl;
        if(left!=NULL) left->printNodo(tab+"_");
        if(right!=NULL) right->printNodo(tab+"_");
}

