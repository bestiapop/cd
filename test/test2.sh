#!/bin/bash
#Quijote
OUT=./test2
mkdir test2
../code -hzciw 1024 -o $OUT/Quijote1.bin ./src/Quijote.txt <./src/Rayuela\ -\ Cortazar.txt
../code -hzcw 1024 -o $OUT/Quijote2.bin ./src/Quijote.txt 
../code -hzciw 1024 -o $OUT/Quijote3.bin ./src/Quijote.txt <./src/Metamorphosis.txt 
../code -hzciw 1024 -o $OUT/Quijote4.bin ./src/Quijote.txt <./src/RANDJShakespeare.txt
#Rayuela
../code -hzcw 1024 -o $OUT/Rayuela1.bin ./src/Rayuela\ -\ Cortazar.txt 
#Rayuela con texto de entrenamiento Quijote
../code -hzciw 1024 -o $OUT/Rayuela2.bin ./src/Rayuela\ -\ Cortazar.txt <./src/Quijote.txt
../code -hzciw 1024 -o $OUT/Rayuela3.bin ./src/Rayuela\ -\ Cortazar.txt <./src/Metamorphosis.txt
../code -hzciw 1024 -o $OUT/Rayuela4.bin ./src/Rayuela\ -\ Cortazar.txt <./src/RANDJShakespeare.txt


#R&J 
../code -hzcw 1024 -o $OUT/RyJ.bin ./src/RANDJShakespeare.txt 
../code -hzcw 1024 -o $OUT/RyJ1.bin ./src/RANDJShakespeare.txt <./src/Metamorphosis.txt 
../code -hzcw 1024 -o $OUT/RyJ2.bin ./src/RANDJShakespeare.txt <./src/Quijote.txt 
../code -hzcw 1024 -o $OUT/RyJ3.bin ./src/RANDJShakespeare.txt <./src/Rayuela\ -\ Cortazar.txt 

#Metamorphosis
../code -hzcw 1024 -o $OUT/Meta.bin ./src/Metamorphosis.txt 
../code -hzciw 1024 -o $OUT/Meta1.bin ./src/Metamorphosis.txt <./src/RANDJShakespeare.txt 
../code -hzciw 1024 -o $OUT/Meta2.bin ./src/Metamorphosis.txt <./src/Rayuela\ -\ Cortazar.txt 
../code -hzciw 1024 -o $OUT/Meta3.bin ./src/Metamorphosis.txt <./src/Quijote.txt 

