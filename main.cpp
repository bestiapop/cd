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
                    cout<<"ws: "<<ws<<endl;
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
    ISettings *settings = fabrica->getSettings();
    
    //Setting debug mode with singleton
    settings->setDebugMode(debug_mode);

    
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
 
   
    return 0;
}
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



 
//
    /*testing
    //algorithmController controller;
    //controller.setHuffmanlz77("a.png","t.sal",1024);
    //cout<<"ok"<<endl;
    //controller.encode_decode(true);
    
    //algorithmController controller2, controller3;
    //codificar 10
    int l= ceil(log2(10+1));
    //cout<<l<<endl;
    int lp = ceil(log2(l+1));
    //cout<<lp<<endl;
    BitOutStream bos2("log");
    bos2.writeLogInt(5);
    bos2.close();
    
    
    BitInStream bis("log");
    cout<<"dec "<<bis.getLogInt()<<endl;
    bis.close();
    
    
    //controller2.setHuffman("a.png", "t.h");   
    //controller2.encode_decode(true);
    //cout<<"termino"<<endl;
    //controller3.setHuffman("t.h","texto.h");
    //controller3.encode_decode(false);


    algorithmController controller;
    controller.setlz77("pg2000.txt","mancha.sal",256);
    controller.encode_decode(true);
    cout<<"end encode"<<endl;
    
    algorithmController controller2;
    controller2.setlz77("mancha.sal","mancha.txt",0);
    controller2.encode_decode(false);
    cout<<"end encode"<<endl;
    //algorithmController controller2;
    //controller2.setHuffman("pg2000.txt","mancha.hu");
    //controller2.encode_decode(true); 
     * 
     * 
    */
    
    /*
    algorithmController controller;
    controller.setHuffmanlz77("a.png","a.bin",70);
    controller.encode_decode(true);
    
    algorithmController controller2;
    controller2.setHuffmanlz77("a.bin","a2.png",70);
    controller2.encode_decode(false);
    */


    //BitOutStream *bos = new BitOutStream("testout");
    //bos->writeLogInt(5);
    //bos->close();
    //BitInStream *bis = new BitInStream("testout");
    //cout<<bis->getLogInt(3);
