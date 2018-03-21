#!/bin/bash

make -C ../../asm
cp ../../asm/asm .

N=`echo ../champs/Car` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42