/* 
 * File:   main.cpp
 * Author: leo
 *
 * Created on September 2, 2014, 6:48 PM
 */

#include <cstdlib>
#include <iostream>
#include "algorithm/Huffman.hpp"
#include "controllers/BitOutStream.hpp"
#include "controllers/BitInStream.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include "algorithm/lz77.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Huffman *h= new Huffman();
    cout<<"Start encode"<<endl;
    //h->code("example.txt","salida.bin");
    //funciona bien
    cout<<"Start decode"<<endl;
    //h->decode("salida.bin","decoded.txt");
    
    //lz77
    lz77* l=new lz77();
    l->code("z","z.bin",10);
    
    return 0;
}

    //ifstream in("example.bin",ios::binary);
    //char c;
    //while((c=in.get())>-1){
    //    cout<<hex<<(int)c<<endl;
    //}
    //in.close();

/*TEST1
    BitOutStream* bos = new BitOutStream("binario.bin");
    bos->writeInt(65535);
    bos->close();
    
    BitInStream* bis = new BitInStream("binario.bin");
    cout<<(long int)bis->getInt()<<endl;
    bis->close();
    */
      
      /*
    bos->writeBit(false);
    bos->writeBit(true);
    bos->writeBit(false);
    bos->writeBit(false);
    bos->writeBit(false);
    bos->writeBit(false);
    bos->writeBit(false);
    bos->writeBit(false);
    bos->writeBit(false);//1
    bos->writeBit(false);//2
    bos->close();
    */

    //ofstream bin("binario.bin",ios::binary);
    //unsigned char n1 = 128;
    //bin.write( reinterpret_cast<const char*>(&n1), sizeof(n1) ) ;
    //bin<<n1;
    
    
    //bin.close();
    
    //BitInStream bis("binario.bin");
    // bis.getBit();
    // bis.getBit();
    //leo2 y leo byte
    //cout<<(int)bis.getChar()<<endl;//128
    
    
    //for(int i=0;i<8;i++)
    //    cout<<bis.getBit();
    
    //int k=2;
    
    //int l= k<<2;
    //cout<<endl<<k<<endl;
    //bool a= (0x01 & 0xFE);
    //cout<<a<<endl;
    //bool a1= (0x01 & 0x01);
    //cout<<a1<<endl;    
    //int n=245;
    //cout<<0x80<<endl;
    //cout<<(1<<7)<<endl;
    
    //cout<<(int)bos->getBuffer()<<endl;


    
    
    
    
    
    
    
    
    
    
    
    
    
    //root->printNodo("_");
    
    //int *prob= h->empiricProbability();
    //Nodo *n= h->generateTree(prob);
    //string a="";
    
    //cout<<"pringd fd"<<endl;
    //n->printNodo(a);    
    /*
    vector<string*> codes= vector<string*>(256);
    for(int i=0; i<256; i++)
        codes[i]=NULL;
    
    h->generateCode(n,codes,"");
    cout<<"ok"<<endl;
    for(int i=0; i<256; i++)
        if (codes[i]!=NULL)
        cout<< *codes[i]<<endl;
    
    BitOutStream bos("salida.bin");
    bos.close();
    */
   /*TEST 
   vector<Nodo*> v= vector<Nodo*>();
   
   Nodo* n1= new Nodo('a',2);
   Nodo* n2= new Nodo('b',7);
   Nodo* n3= new Nodo('c',1);
   v.push_back(n1);
   v.push_back(n2);
   v.push_back(n3);
   sort(v.begin(),v.end());
   
   //for(int i=0;i<v.size();i++)
   //    cout<<v[i]->getChar()<<endl;
    //for(int i=0;i<256;i++)
    //cout<<(char) i<<endl;
   */
   

    //for(int i=0; i<256; i++)
    //    cout<<prob[i]<<endl;
    

