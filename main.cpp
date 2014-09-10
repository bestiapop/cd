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
    string in_file;
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
                in_file=string(optarg);
                break;
                
            case 'c':
                compress=true;
                //if(xtract){
                //    compress=false;
                //}
                //in_file=string(optarg);
                //args[1]=string(optarg);
                break;
                
            case 'x':
                //if(optarg==NULL){
                //    cout<<"option -c requires in file to decode\n";
                //    return -1;
                //}
                compress=false;
                //if(compress){
                //    xtract=false;
                //    in_file=string(optarg);
                //}
                
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
                cout<<optopt<<endl;
                cout<<optarg<<endl;
                if(optopt=='z') cout<<"option -z requires argument \n";
                else
                    if(optopt=='i') cout<<"option -i requires input file \n";
                break;
            default:
                return -1;
        }
    }
    
    in_file= string(argv[optind]);
    
//    for (int index = optind; index < argc; index++)
//         cout<<"Non-option argument"<< argv[index]<<endl;

    
    algorithmController controller;
   
    if(h && !lz){
        cout<<"HUFFMAN"<<endl;
        controller.setHuffman(compress,in_file);
        cout<<in_file<<endl;
        controller.encode_decode(compress);
    }
    else if(h && lz){
        cout<<"HUFFMAN+LZ"<<endl;
        //WSSS!
        controller.setHuffmanlz77(compress,in_file,10);
        controller.encode_decode(compress);
        //
    }
    else if(!h && lz){
        cout<<"LZ"<<endl;
        ////////WSSSS!
        cout<<in_file<<endl;

        controller.setlz77(compress,in_file,10);
        controller.encode_decode(compress);
    }
    else{ 
        cout<<"LZdef"<<endl; //default
    }

    /*testing
    algorithmController controller;
    controller.setlz77(true,"z",10);
    cout<<"ok"<<endl;
    controller.encode_decode(true);
    
    
    controller.setlz77(false,"z.bin",10);
    controller.encode_decode(false);
    */
    return 0;
           
}
