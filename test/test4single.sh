#!/bin/bash
INSTANCES=./src
file=Quijote.txt
	for n in 256 1024 4096 1048576
	do
		./cd -hzcw $n ./src/$file -o ./bin/test3/$file-$n.bin
	done
