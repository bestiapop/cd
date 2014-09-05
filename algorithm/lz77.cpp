/* 
 * File:   lz77.cpp
 * Author: leo
 * 
 * Created on September 4, 2014, 3:08 AM
 */

#include "lz77.hpp"
#include "../structures/FiniteBuffer.hpp"

lz77::lz77() {
}

lz77::lz77(const lz77& orig) {
}

lz77::~lz77() {
}

void lz77::code(string name_in, string name_out, int ws) {
    
    BitOutStream bos(name_out);
    BitInStream bis(name_in);
  
    char c1;///= bis.getChar();
    while((c1=bis.getChar())>-1) cout<<c1<<"XX"<<endl;
    bis.close();
    bis.open(name_in);
    
    Method *m = new byteMethod(bis,bos);    
    FiniteBuffer *buffer= new FiniteBuffer(ws);
    
    int pos_current=0;   
    char ch=m->readChar();
    buffer->push(ch); 

    
    while(ch>-1){
    //char to_write=ch;
    int offset=0;
    int length=0;   

    //cout<<"currentpos:"<<pos_current<<"   "<<buffer->at(pos_current)<<endl;
    for(int i=0; i<pos_current;i++){
        int i_aux=i;
        int count=0;
        int pos_aux=pos_current;
        char c=ch;

        while(c>-1 && buffer->at(pos_aux)==buffer->at(i_aux) && i_aux<=pos_current+1){
            pos_aux++;
            i_aux++;       
            count++;
            if(pos_aux>buffer->length()-1){
                c=m->readChar();
                ch=c;
                if(c>-1){
                    buffer->push(c);                    
                }
            }else
                c=buffer->at(pos_aux); 
        }
        if(count>3 && count>length){
            //offset= largo-i;
            offset= pos_current-i;
            length=count;
        } 
    }//for
        
    if(length>3){
        cout<<"("<<length<<","<<offset<<")"<<endl;
        //m->writeBit(true);
        //m->writeChar((unsigned char)length);
        //m->writeChar((unsigned char)offset);
    }
        //cout<<to_write<<endl;
        cout<<"["<<buffer->at(pos_current)<<"]"<<endl;
        //m->writeChar((unsigned char)to_write);
        
        
        //if(buffer->length()-1>pos_current ||length<4){
        //    cout<<buffer->length()<<" "<<pos_current<<endl;
        //   pos_current++; //aumento 1
        //    ch=buffer->at(pos_current);
        //}
        
        
        //buffer->wrap();
        if(length>3){
            //cout<<"lenopantes"<<ch<<endl;
            if(!(buffer->length()-1>pos_current)){
                ch=m->readChar();
                buffer->push(ch);
            }
            //ch=m->readChar();           
            //buffer->push(ch); //new
            pos_current+=length;
            //cout<<"lenop"<<ch<<endl;
            //ch= buffer->at(pos_current);
        }
        else{
            //ch=m->readChar();
            //buffer->push(ch);
            if(!(buffer->length()-1>pos_current)){
                ch=m->readChar();
                buffer->push(ch);
            }
            pos_current++;
            ch=buffer->at(pos_current);
            //cout<<"else:"<<ch<<endl;
        }
        

    }//while    
    
    m->close();

}




void lz77::code2(string name_in, string name_out, int ws) {
    
    BitOutStream bos(name_out);
    BitInStream bis(name_in);

    Method *m = new byteMethod(bis,bos);
    //vector<char> *v= new vector<char>();
    
    FiniteBuffer *buffer= new FiniteBuffer(ws);
    //buffer->push('c');
    //string to_code="aaaaaakkkkkkkkkkkkkk\0";
    string to_code="aaakkk\0";
    
    
    //windows size
    //int ws=10;
    
    //best
    int offset=0;
    int length=0;
    
    //no me sirven las primeras 3, no matcheo mayor que 3
    //for(int j=0;j<3;j++) cout<<to_code.at(j)<<endl;
    int currentPos=0;
    
    char c;
    //while((c=m->)>-1){//
    //long int length_file= 
    
    
    while(currentPos<to_code.length()){
    int offset=0;
    int length=0;    
    cout<<"currentpos:"<<currentPos<<endl;    
    int posIt=max(currentPos-ws,0);
    unsigned char c= to_code.at(currentPos);
         
    //unsigned char c= ch;
    
    for(int i=posIt; i<currentPos;i++){ //no me sirve 2
    //for(int i=0; i<ws;i++){  
        int pos_aux=currentPos;
        int i_aux=i;
        int count=0;
        while(  pos_aux<to_code.length() && 
                to_code.at(pos_aux)==to_code.at(i_aux) &&
                i_aux<=currentPos+1){
        //char ch2;
            pos_aux++;
            //buffer->push(ch2);
            i_aux++;       
            count++;
        }
        
        
        if(count>3 && count>length){
            offset=currentPos-i;
            //offset= ws-i;
            //offset= largo-i;
            length=count;
        } 
    }//for
        
    if(length>3){
        cout<<"("<<length<<","<<offset<<")"<<endl;//c<<")"<<endl;
        //m->writeBit(true);
        //m->writeChar((unsigned char)length);
        //m->writeChar((unsigned char)offset);
    }else{
        //m->writeBit(false);
        //m->writeChar(c);
        //cout<<c<<endl;
        
    }
    cout<<c<<endl;
    if(length>3)
        currentPos+= length;
    else
        currentPos++;
    }//while    
    
    bos.close();
    bis.close();
    }

/*

void lz77::writeByte(BitOutStream &bos, unsigned char c) {
        bos.writeByte(c);
}

void lz77::writeHuffman(BitOutStream &out, vector<string*> &code, unsigned char c){
    string *toParse= code[c];
    for(int i=0;i<toParse->length();i++){
        if(toParse->at(i)=='0')
            out.writeBit(false);//filewrite<<false;   
        else
            out.writeBit(true);//filewrite<<true;          
    }
}
*/