/* 
 * File:   lz77.cpp
 * Author: leo
 * 
 * Created on September 4, 2014, 3:08 AM
 */

#include "lz77.hpp"

lz77::lz77(){
}

lz77::lz77(int ws,string filein, string fileout):Algorithm(filein,fileout){
    this->ws=ws;
    bos= new BitOutStream(fileout);
    bis= new BitInStream(filein);
}


lz77::lz77(const lz77& orig) {
}

lz77::~lz77() {
}



void lz77::lz77algorithm() {
    
    FiniteBuffer buffer(ws, bis);
    
    while(buffer.length_b()>0){
    int offset=0;
    int length=0;

    for(int i=0; i<buffer.length_w();i++){
        int i_aux=i;
        int aux=0;
        int largo=0;
        int offseta=0;
        while(aux<buffer.length_b() && i_aux<buffer.length_w() && buffer.at_w(i_aux)==buffer.at_b(aux)){
            i_aux++;
            aux++;
            largo++;
            offseta=buffer.length_w()-i;
        }
        //otro while
        if(i_aux==buffer.length_w()){
            i_aux=0;
            while(aux<buffer.length_b() && buffer.at_b(i_aux)==buffer.at_b(aux)){
                offseta=buffer.length_w()-i;
                i_aux++;
                aux++;
                largo++;
            }
        
        }
        
        if(largo>length ){
            length=largo;
            offset=offseta;
        }
    
    }
    
    if(length>3){
        //cout<<"("<<length<<","<<offset<<")"<<endl;
        bos->writeBit(true);
        bos->writeByte((unsigned char)length);
        bos->writeByte((unsigned char)offset);
    }
    else{
        length=1;
        //cout<<"["<<buffer.at_b(0)<<"]"<<endl;
        bos->writeBit(false);
        bos->writeChar(buffer.at_b(0));
    }
    
    buffer.shiftbuffer(length,bis);
    
    if(buffer.length_b()!=0)
        bos->writeBit(false);    
    else
        bos->writeBit(true);    
    }

    bis->close();
    bos->close();
}



void lz77::lz77decode() {
    char * buffer = new char[ws];
    long int it=0;
    long int it_aux;
    bool end=false;
    while(!end){
        bool bit=bis->getBit();
        if(bit){ //1
            int length= (int)bis->getByte();
            int offset= (int)bis->getByte();
            end= bis->getBit();
            it_aux= it-offset;
            //cout<<"off: "<<offset<<endl;
            it+=length;
            //cout<<"while"<<it<<" "<<length<<endl;
            while(length>0 ){//|| it_aux<=it){
                cout<<buffer[it_aux%ws]<<endl;
                buffer[(it_aux+offset)%ws]=buffer[it_aux%ws];
                //print in file
                bos->writeByte(buffer[it_aux%ws]);
                it_aux++;
                length--;
            }
            //it=it_aux+1; //added +1
            
        }else{//single char
            //cout<<"IT:single"<<it<<endl;
            buffer[it%ws]=bis->getChar();
            end=bis->getBit();
            //cout<<buffer[it%ws]<<endl;
            //print in file
            bos->writeByte(buffer[it%ws]);
            it++;           
        }   
    }
    
    bos->close();
    bis->close();
    delete [] buffer;
}


void lz77::encode() {
    lz77algorithm();
}

void lz77::decode() {
    lz77decode();
}
