/* 
 * File:   Markov.hpp
 * Author: leo
 *
 * Created on November 4, 2014, 6:34 PM
 */

#ifndef MARKOV_HPP
#define	MARKOV_HPP
#include <string>

using namespace std;
class Markov {
public:
    Markov();
    Markov(const Markov& orig);
    virtual ~Markov();
    void initMask(int k);
    void createTestFile(string fileout, int k);
    void createFile(string filename, string fileout, int fz);
    void functionKT(string infile, int KM);
    double calcKT(bool, int, int, long int&, long int&);
    //void test(int);
    double KT(int k, unsigned char c, long int &a, long int &b);
    long int mcmfunc(long int a, long int b);

    
private:
    unsigned char mask;
};

#endif	/* MARKOV_HPP */

