#!/bin/bash

make -C ../../asm
cp ../../asm/asm .

echo "\nUnknown instruction-------"
N=`echo ../champs/errors/unknown_instruction` S=`echo $N.s` && ./asm $S
echo "\nWrong param number-------"
N=`echo ../champs/errors/bad_param_nb` S=`echo $N.s` && ./asm $S
echo "\nWrong param type-------"
N=`echo ../champs/errors/bad_param_type` S=`echo $N.s` && ./asm $S
echo "\nBad character in param-------"
N=`echo ../champs/errors/bad_char_in_param` S=`echo $N.s` && ./asm $S
echo "\nNonexistent label-------"
N=`echo ../champs/errors/nonexistent_label` S=`echo $N.s` && ./asm $S
echo "\nNo code-------"
N=`echo ../champs/errors/no_code` S=`echo $N.s` && ./asm $S
echo "\nNo name-------"
N=`echo ../champs/errors/no_name` S=`echo $N.s` && ./asm $S
echo "\nNo comment-------"
N=`echo ../champs/errors/no_comment` S=`echo $N.s` && ./asm $S
echo "\nName and comment too long-------"
N=`echo ../champs/errors/name_com_too_long` S=`echo $N.s` && ./asm $S


