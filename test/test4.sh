#!/bin/bash
INSTANCES=./src
for file in $(ls $INSTANCES); do	
	../code -hdc ./src/$file -o ./test4/$file.bin >./test4/Res-$file.txt
done
