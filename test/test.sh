#!/bin/bash
H=../code
ext="h"

echo "Testing Huffman..."
for i in {1..3}; do
	file="t$i"
	fileo="$file$ext"
	$H -hc $file -o ./bin/$fileo.$ext
	$H -hx ./bin/$fileo.$ext -o ./bin/$fileo
	diff $file ./bin/$fileo >./bin/$fileo.sal
	if [[ -s ./bin/$fileo.sal ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done

echo "Testing LZ77..."
ext="z"
for i in {1..3}; do
	file="t$i"
	fileo="$file$ext"
	$H -zc $file -o ./bin/$fileo.$ext
	$H -zx ./bin/$fileo.$ext -o ./bin/$fileo
	diff $file ./bin/$fileo >./bin/$fileo.sal
	if [[ -s ./bin/$fileo.sal ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done


echo "Testing LZ77+HUFFMAN..."
ext="hz"
for i in {1..3}; do
	file="t$i"
	fileo="$file$ext"
	$H -hzc $file -o ./bin/$fileo.$ext
	$H -hzx ./bin/$fileo.$ext -o ./bin/$fileo
	diff $file ./bin/$fileo >./bin/$fileo.sal
	if [[ -s ./bin/$fileo.sal ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done

#../code -hzix t1.hz -o t1.extra <t1

echo "Testing LZ77+HUFFMAN+File..."
ext="hzf"
for i in {1..3}; do
	file="t$i"
	fileo="$file$ext"
	$H -hzic $file -o ./bin/$fileo.$ext <t1
	$H -hzix ./bin/$fileo.$ext -o ./bin/$fileo
	diff $file ./bin/$fileo >./bin/$fileo.sal
	if [[ -s ./bin/$fileo.sal ]] ; then
	  echo "ERROR: $file"
	else
  	  echo "OK: $file"
	fi ;
done


