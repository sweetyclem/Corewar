#!/bin/bash

make -C ../../asm
cp ../../asm/asm .

N=`echo ../champs/Car` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/Gagnant` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/barriere` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/ex` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/jumper` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/maxidef` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/mortel` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/Octobre_Rouge_V4.2` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/slider2` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/test` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
N=`echo ../champs/toto` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ../asm42 $S && hexdump $COR > testasm42 && diff testasm testasm42
