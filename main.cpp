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
#include "interfaces/Factory.hpp"

using namespace std;

int main(int argc, char** argv) {
    
    int c;
    int ws_int;

    bool lz=false;
    bool h=false;
    bool compress=false;
    bool hfromfile=false;
 
    string output_file;
    string in_file;
    string ws;
    

    
    while((c=getopt(argc,argv,"cxhzidwo:"))!=-1){
        switch(c){
            case 'o':
                output_file= string(optarg);
                break;
                
            case 'i': //cases huffman with example file
                hfromfile = true;
                break;
                
            case 'c':
                compress=true;
                break;
                
            case 'x':
                compress=false;           
                break;
                
            case 'h':
                h=true;
                break;
                
            case 'z':
                lz=true;
                break;
                
            case 'w':
                if(optarg==NULL){
                    cout<<"option -w requires window size value\n";
                    return -1;
                }else{
                    ws=string(optarg);
                    try{
                        stringstream ss(ws);        
                        ss>>ws_int;
                        if(ws_int<=0){
                            cout<<"Window size must be greater than 0..."<<endl;
                            return 0;
                        }
                    }catch(exception E){
                        cout<<"Invalid argument for Window Size..."<<endl;
                        return 0;        
                    }
                }
                break;
                
            case '?':
                //cout<<optopt<<endl;
                //cout<<optarg<<endl;
                if(optopt=='z') cout<<"option -z requires argument \n";
                else
                    if(optopt=='i') cout<<"option -i requires input file \n";
                break;
            default:
                return -1;
        }
    }
    
    in_file= string(argv[optind]);

    Factory *fabrica = new Factory();
    IAlgorithms *algorithms = fabrica->getAlgorithms();
    
    if(h && !lz){
        cout<<"HUFFMAN"<<endl;
        algorithms->executeHuffman(in_file,output_file,compress);
    }
    else if(h && lz){
        cout<<"HUFFMAN+LZ"<<endl;
        algorithms->executeHuffmanLZ77(in_file,output_file,ws_int, hfromfile, compress);
    }
    else if(!h && lz){
        cout<<"LZ"<<endl;
        algorithms->executeLZ77(in_file, output_file, ws_int, compress);
    }
    else{ 
        cout<<"LZdef"<<endl; //default
        algorithms->executeLZ77(in_file, output_file, ws_int, compress);    
    }
     

    /*testing
    algorithmController controller;
    controller.setlz77(true,"z","z.sal",10);
    cout<<"ok"<<endl;
    controller.encode_decode(true);
    
    
    controller.setlz77(false,"z.sal","z.comp",10);
    controller.encode_decode(false);
    */
    /*algorithmController controller;
    controller.setlz77("a.txt","a.bin",70);
    controller.encode_decode(true);
    
    algorithmController controller2;
    controller2.setlz77("a.bin","a2.txt",70);
    controller2.encode_decode(false);    */
    /*
    algorithmController controller;
    controller.setHuffmanlz77("a.png","a.bin",70);
    controller.encode_decode(true);
    
    algorithmController controller2;
    controller2.setHuffmanlz77("a.bin","a2.png",70);
    controller2.encode_decode(false);
    */
    return 0;
    
    /*
    algorithmController controller;

    cout<<"LPM"<<endl;
    controller.setHuffman("music.mp3", "ab.bin");
    //controller.setHuffman("a.txt","a.sal");
    controller.encode_decode(true);
      
    algorithmController controller2;
    controller2.setHuffman("ab.bin","music2.mp3");
    controller2.encode_decode(false);
    */
}
