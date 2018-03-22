#!/bin/sh

make -C ../../asm && cp ../../asm/asm .
N=`echo ../champs/Asombra` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/Kappa` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/Machine-gun` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/MarineKing` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/Misaka_Mikoto` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/Rainbow_dash` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/THUNDER` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/Varimathras` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/Wall` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/_` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/_honeybadger` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/bee_gees` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/big_feet` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/big_life` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/bigzork` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/casimir` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/champ` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/corelol` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/darksasuke` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/doge` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/dubo` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/fat_42` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/fluttershy` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/gedeon` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/helltrain` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/jinx` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/justin_bee` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/littlepuppy` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/live` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/loose` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/mandragore` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/meowluigi` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/salamahenagalabadoun` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/sam_2.0` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/seg` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/skynet` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/terminator` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/test` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/turtle` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/ultimate-surrender` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/while_fork` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/youforkmytralala` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
N=`echo ../champs/zork` S=`echo $N.s` COR=`echo $N.cor` && ./asm $S && hexdump $COR > testasm && ./asmHugo $S && hexdump $COR > testasmHugo && diff testasm testasmHugo
rm ../champs/*.cor
