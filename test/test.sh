#!/bin/bash
H=../code

mkdir ./bin
mkdir ./xtract
mkdir ./compare
INSTANCES=./src
echo "Testing Huffman..."
ext="h"
CA="-hc"
XA="-hx"
for file in $( ls $INSTANCES); do
	#file="t$i"
	#fileo="$file$ext"
	$H -hc ./src/$file -o ./bin/$file.$ext
	$H -hx ./bin/$file.$ext -o ./xtract/$file
	diff $INSTANCES/$file ./xtract/$file >./compare/$file.diff
	if [[ -s ./bin/$file.diff ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done

echo "Testing LZ77..."
ext="z"
CA="-zcw 256"
XA="-zx"
for file in $( ls $INSTANCES); do
	#file="t$i"
	#fileo="$file$ext"
	$H $CA ./src/$file -o ./bin/$file.$ext
	$H $XA ./bin/$file.$ext -o ./xtract/$file
	diff $INSTANCES/$file ./xtract/$file >./compare/$file.diff
	if [[ -s ./bin/$file.diff ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done



echo "Testing LZ77+HUFFMAN..."
ext="hz"
CA="-hzcw 256"
XA="-hzx"
for file in $( ls $INSTANCES); do
	#file="t$i"
	#fileo="$file$ext"
	$H $CA ./src/$file -o ./bin/$file.$ext
	$H $XA ./bin/$file.$ext -o ./xtract/$file
	diff $INSTANCES/$file ./xtract/$file >./compare/$file.diff
	if [[ -s ./bin/$file.diff ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done

#../code -hzix t1.hz -o t1.extra <t1

echo "Testing LZ77+HUFFMAN+File..."
ext="hzf"
CA="-hzciw 256"
XA="-hzx"
for file in $( ls $INSTANCES); do
	#file="t$i"
	#fileo="$file$ext"
	$H $CA ./src/$file -o ./bin/$file.$ext
	$H $XA ./bin/$file.$ext -o ./xtract/$file <./src/Quijote.txt
	diff $INSTANCES/$file ./xtract/$file >./compare/$file.diff
	if [[ -s ./bin/$file.diff ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done

