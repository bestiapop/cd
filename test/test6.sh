#!/bin/bash
INSTANCES=./src
PROG=../code
mkdir test6/data
for file in $(ls $INSTANCES); do	
	$PROG -hzdcw 256 ./src/$file -o ./test6/$file.bin > ./test6/data/$file
done

#WS 1MB
$PROG -hzdcw 1048576 ./src/RayuelaCortazar.txt -o ./test6/Rayuela.bin > ./test6/data/Cortazar-1mb.txt
