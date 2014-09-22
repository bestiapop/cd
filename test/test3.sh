#!/bin/bash
INSTANCES=./src
for file in $(ls $INSTANCES); do
	for n in 256 1024 4096 1048576
	do
		../code -hzcw $n ./src/$file -o ./bin/test3/$file-$n.bin
	done
done
