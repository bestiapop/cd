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
#include <unistd.h>
#include "algorithm/lz77.hpp"
#include "algorithm/Algorithm.hpp"
#include "controllers/algorithmController.hpp"
using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    //GetOpt getopt (argc, argv, "dcs:");
    
    Lista args= Lista(3);
    int c;
    bool lz=false;
    bool h=false;
    bool compress=false;
    bool xtract=false;
    string h_file;
    string i_file; 
    string ws;
    
    //z == lz algorithm
    //h == huffman
    //
    
    while((c=getopt(argc,argv,"cxhzidw"))!=-1){
        switch(c){
            case 'i':
                if(optarg==NULL){
                    cout<<"option -i requires argument\n";
                    return -1;
                }
                i_file=string(optarg);
                break;
                
            case 'c':
                compress=true;
                if(xtract){
                    compress=false;
                }
                //args[1]=string(optarg);
                break;
                
            case 'x':
                //if(optarg==NULL){
                //    cout<<"option -c requires in file to decode\n";
                //    return -1;
                //}
                xtract=true;
                if(compress){
                    xtract=false;
                }
                
                break;
                
            case 'h':
                //if(optarg!=NULL)
                //    h_file=string(optarg);
                h=true;
                break;
                
            case 'z':
                lz=true;
                break;
                
            case 'w':
                if(optarg==NULL){
                    cout<<"option -w requires window size value\n";
                    return -1;
                }
                ws=string(optarg);
                break;
                
            case '?':
                //cout<<optopt<<endl;
                if(optopt=='z') cout<<"option -z requires argument \n";
                else
                    if(optopt=='i') cout<<"option -i requires input file \n";
                break;
            default:
                return -1;
        }
    }
    
    /*
    
    for (int index = optind; index < argc; index++)
         cout<<"Non-option argument"<< argv[index]<<endl;
    
    if(lz) cout<<"window size: "<< ws <<endl;
    cout<<i_file<<endl;
    cout<<optopt<<endl;    
       
        */
    
    /*
    Algorithm *algorithm;
    
    Lista args2= Lista(3);
    //args.push_back("z");
    cout<<"ok"<<endl;
    
    args2[0]=string("z");
    args2[1]="z.bin";
    args2[2]="10";
    algorithm = new Huffman();
    //Huffman *huff= new Huffman();
    algorithm->encode(args2);
    
     * 
     * 
     */
    
    
    Lista args2= Lista(3);
    cout<<"ok"<<endl;
    
    args2[0]=string("z");
    args2[1]="z.bin";
    args2[2]="10";
    
    
    algorithmController controller;//= new algorithmController();
    
    if(h && !lz){
        cout<<"HUFFMAN"<<endl;
        controller.setAlgorithm(1,args2[0],args2[1]);
        //controller.encode();
    }
    else if(h && lz){
        cout<<"HUFFMAN+LZ"<<endl;
        //
    }
    else if(!h && lz){
        cout<<"LZ"<<endl;
        
    }
    else{ 
        cout<<"LZ"<<endl; //default
    }
    
    BitInStream bis("z");
    BitOutStream bos("z.bin");
    
    Huffman *huff= new Huffman();
    huff->encode(bis,bos);
    bis.close(); bos.close();
    
    BitInStream bis2("z.bin");
    BitOutStream bos2("z.out");
    huff->decode(bis2,bos2);
    //controller.setAlgorithm(1,"z.bin","z.out");
    //controller.decode();
    //controller.encode();

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
    

