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
    bool debug_mode=false;
    
    string output_file;
    string in_file;
    string ws;
    
    while((c=getopt(argc,argv,"cxhzidw:o:"))!=-1){
        switch(c){
            case 'd' :
                debug_mode = true;
                break;
                
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
                    //cout<<"ws: "<<ws<<endl;
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
    ISettings *settings = fabrica->getSettings();
    
    //Setting debug mode with singleton
    settings->setDebugMode(debug_mode);

    
    if(h && !lz){
        //cout<<"HUFFMAN"<<endl;
        algorithms->executeHuffman(in_file,output_file,compress);
    }
    else if(h && lz){
        //cout<<"HUFFMAN+LZ"<<endl;
        algorithms->executeHuffmanLZ77(in_file,output_file,ws_int, hfromfile, compress);
    }
    else if(!h && lz){
        //cout<<"LZ"<<endl;
        algorithms->executeLZ77(in_file, output_file, ws_int, compress);
    }
    else{ 
        //cout<<"LZdef"<<endl; //default
        algorithms->executeLZ77(in_file, output_file, ws_int, compress);    
    }
 
   
    return 0;
}