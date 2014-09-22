#!/bin/bash
#Quijote
../code -hzciw 1024 -o Quijote1.bin ./src/Quijote.txt <./src/Rayuela\ -\ Cortazar.txt
../code -hzcw 1024 -o Quijote2.bin ./src/Quijote.txt 
../code -hzciw 1024 -o Quijote3.bin ./src/Quijote.txt <./src/Metamorphosis.txt 
../code -hzciw 1024 -o Quijote4.bin ./src/Quijote.txt <./src/RANDJShakespeare.txt
#Rayuela
../code -hzcw 1024 -o Rayuela1.bin ./src/Rayuela\ -\ Cortazar.txt 
#Rayuela con texto de entrenamiento Quijote
../code -hzciw 1024 -o Rayuela2.bin ./src/Rayuela\ -\ Cortazar.txt <./src/Quijote.txt
../code -hzciw 1024 -o Rayuela3.bin ./src/Rayuela\ -\ Cortazar.txt <./src/Metamorphosis.txt
../code -hzciw 1024 -o Rayuela4.bin ./src/Rayuela\ -\ Cortazar.txt <./src/RANDJShakespeare.txt


#R&J 
../code -hzcw 1024 -o RyJ.bin ./src/RANDJShakespeare.txt 
../code -hzcw 1024 -o RyJ1.bin ./src/RANDJShakespeare.txt <./src/Metamorphosis.txt 
../code -hzcw 1024 -o RyJ2.bin ./src/RANDJShakespeare.txt <./src/Quijote.txt 
../code -hzcw 1024 -o RyJ3.bin ./src/RANDJShakespeare.txt <./src/Rayuela\ -\ Cortazar.txt 

#Metamorphosis
../code -hzcw 1024 -o Meta.bin ./src/Metamorphosis.txt 
../code -hzciw 1024 -o Meta1.bin ./src/Metamorphosis.txt <./src/RANDJShakespeare.txt 
../code -hzciw 1024 -o Meta2.bin ./src/Metamorphosis.txt <./src/Rayuela\ -\ Cortazar.txt 
../code -hzciw 1024 -o Meta3.bin ./src/Metamorphosis.txt <./src/Quijote.txt 







