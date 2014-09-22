#!/bin/bash
#concateno archivos
cat ./src/kern.log   ./src/RANDJShakespeare.txt ./src/medsamp2014.xml ./src/RayuelaCortazar.txt ./src/diario.html ./src/Metamorphosis.txt  ./src/xfst ./src/FL_insurance_sample.csv  ./src/Quijote.txt >concatenado.bin

../code -hcd -o concat.bin concatenado.bin

