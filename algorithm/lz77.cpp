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
    bos->writeInt(ws);
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
            bool ok=true;
            if(aux==buffer.length_b()){//igual maximo
                ok=buffer.push(bis);
            }
            //while(aux<buffer.length_b() && buffer.at_b(i_aux)==buffer.at_b(aux)){
            while(buffer.at_b(i_aux)== buffer.at_b(aux)){

                offseta=buffer.length_w()-i;
                i_aux++;
                aux++;
                largo++;
                if(aux == buffer.length_b()){
                    ok=buffer.push(bis);
                }
            }
        
        }
        
        if(largo>length ){
            length=largo;
            offset=offseta;
        }
    
    }
    
    if(length>1){
        //cout<<"("<<length<<","<<offset<<")"<<endl;
        bos->writeLogInt(length);
        bos->writeIntWS(ws,offset);
    }
    else{
        length=1;
        //cout<<"["<<(char)buffer.at_b(0)<<"]"<<endl;
        bos->writeBit(true); //false
        bos->writeChar(buffer.at_b(0));
    }
    
    if(Utils::instance()->getDebugMode())
        cout<<"("<<length<<","<<bos->getSize()<<")"<<endl;

    buffer.shiftbuffer(length,bis);
    
    }

    bis->close();
    bos->close();
}



void lz77::lz77decode() {
    ws= bis->getInt();
    char * buffer = new char[ws];
    long int it=0;
    long int it_aux;
    //while(it<lfile){
    while(bis->valid()){
        long int length=bis->getLogInt();
        if(length>1){
        long int offset= bis->getInt(ws);
            it_aux= it-offset;
            it+=length;
            while(length>0 ){
                buffer[(it_aux+offset)%ws]=buffer[it_aux%ws];
                bos->writeByte(buffer[it_aux%ws]);
                it_aux++;
                length--;
            }            
        }else if(length == 1){//single char
            buffer[it%ws]=bis->getChar();
            bos->writeByte(buffer[it%ws]);
            it++;           
        }  
    }
    
    bos->close();
    bis->close();
    delete [] buffer;
}


void lz77::encode() {
    //long int lfile= bis->fileLength()+1;
    //bos->writeInt(lfile);
    //bis->open(_filein);
    lz77algorithm();
}

void lz77::decode() {
    
    lz77decode();
}
