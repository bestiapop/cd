/* 
 * File:   Markov.cpp
 * Author: leo
 * 
 * Created on November 4, 2014, 6:34 PM
 */

#include <fstream>
#include <cmath>
#include <map>
#include <algorithm>
#include <random>
#include <bitset>

#include "Markov.hpp"
#include "BitOutStream.hpp"
#include "BitInStream.hpp"
#define L 1 // l de la letra 4 bytes
//optimiza lectura escritura

Markov::Markov() {
}

Markov::Markov(const Markov& orig) {
}

Markov::~Markov() {
}

void Markov::initMask(int k) {
    mask=0;
    for (int i=0; i<k; i++){
        mask = (mask<<0x01) | 0x01;
    }
}

void Markov::createTestFile(string fileout, int k) {
    ofstream f;
    f.open(fileout);
    f << k << endl;
    random_device rd;
    int lines = pow(2, k);
    for(unsigned char c=0; c<lines; c++){
        std::mt19937 gen(rd());
        uniform_real_distribution<> dis(0, 1);
        double r = dis(gen);
        bitset<8> bs(c);
        if(k==0)
            f << "_";
        else{
        for(int i=k-1; i>=0; i--)
            f << bs[i];
        }
        f << " " << r << endl;
    }
    f.close();
}


void Markov::createFile(string filename, string fileout, int fz) {
    BitOutStream bos(fileout);
    map<unsigned char, float> dic;
    ifstream file(filename.c_str());
    //read k
    int k;
    file >> k;
    int lines = pow(2, k);
    string ord;
    float prob;
    for(unsigned char i=0; i<lines; i++){
        file >> ord >> prob;
        dic[i] = prob;      
    }
    
    map<unsigned char, float>::iterator fin = dic.end();
    for(map<unsigned char, float>::iterator it=dic.begin(); it!=fin; ++it){
        cout << (int)it->first << it->second << endl;
    }
    
    //init mask
    initMask(k);
    cout<< "mask: "<<(int)mask<<endl;
    
    unsigned char c;
    random_device rd;
    unsigned char state = 0;
    for (int i=0; i<fz; i++){
        for(int k=0; k<8; k++){
            std::mt19937 gen(rd());
            uniform_real_distribution<> dis(0, 1);
            double r = dis(gen);
            cout << "r: " << r <<endl;
            if(r<dic[state]){
                state = (state << 0x01) & mask;
                bos.writeBit(false);
            }else{
                state = ((state << 0x01) | 0x01) & mask;
                bos.writeBit(true);
            }
        cout << "state: "<<(int)state << endl;    
        }
    
    }
    bos.close();
}


void Markov::functionKT(string infile, int KM) {
    BitInStream bis(infile);
    //leo archivo y calculo KT
    double kt=0;
    unsigned char c;
    int blocks = 0;
    long int a, b;
    while(bis.valid()){
        blocks++;
        //consumo L bytes me quedo con el ultimo
        //for(int i=0; i<L; i++)
        c =  (unsigned char)bis.getByte();
        
        double prob =KT(KM,c,a,b);
        double adivb =(double)a/b;
        //cout<<log2(adivb)<<endl;
        kt+=(-adivb*(log2(adivb)));

        //KT = KT + log2((zeros+0.5)/(KM+1));
    }
    cout <<log2(blocks)/blocks<< " " <<-kt<<endl;//-kt/blocks << endl;
    bis.close();
}

double Markov::calcKT(bool one, int ceros, int unos, long int& a, long int &b) {
    int t = ceros + unos;
    a = ((2*unos)+1.0);
    b = (2*(t+1));
    if(!one)
        a = b-a;
    double kt=a/b;
    //cout<<kt<<endl;
    if (one)
        return  -(log2(unos+0.5)-log2(t+1)); //-log2(kt);//
    else
        return  -(log2(ceros+0.5)-log2(t+1)); //-log2(1-kt);
}


double Markov::KT(int K,unsigned char c, long int& n, long int& n1) {
    //int K=3;
    long int a, b;
    n=n1=1;
    initMask(K);
    int K2 = pow(2,K);
    int * ceros = new int [K2];
    int * unos = new int [K2];
    for(int i=0; i<K2; i++){
        ceros[i]=0;
        unos[i]=0;
    }
    
    int state=0;
    double KT=0;
    for(int i=0; i<8; i++){
        bool bit= c & 0x80;//0x02;//0x80;
        //cout<<bit;
        KT += calcKT(bit, ceros[state], unos[state],a,b);
        n*=a;
        n1*=b;
        if (bit){
            unos[state]++;
            state = ((state << 1) | 0x01) & mask;
        }
        else{
            ceros[state]++;
            state = (state << 1) & mask;
        }
        c = c << 1;  
    }
    long int d = mcmfunc(n,n1);
    n=n/d;
    n1=n1/d;
    //cout<<" "<<n <<"/"<<n1<<endl;
    delete [] ceros;
    delete [] unos; 
    //cout<<KT<<"  "<<n<<"/"<<n1<<endl;
    return KT;
    
}

long int Markov::mcmfunc(long int a, long int b) {
    long int mcm = min(a,b);
    for(long int i=mcm; i>0; i--)
        if (b%i==0 && a%i==0)
            return i;
    
}
