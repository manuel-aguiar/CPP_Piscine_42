#!/bin/bash

# out file
out_file="test_RPN_output.txt"
program="RPN"
#test inputs
inputs=(
	" "
    "3"
    "+7 7 +"
    "-7 7 +"
    "7 7 7 +"
    "7 7 7 * -"
    "7 7 * 7 -"
    "1 2 * 2 / 2 * 2 4 - +"
    "(1 + 1)"
    "hello potato"
    "3   5   +    /     -"
    " 3 4 +"
    "3 4 +"
)

#remove previous outfile if it exists
rm -f $out_file

#loop through inputs and run
for input in "${inputs[@]}"
do
	echo -e "input is: \"$input\""  >> $out_file
    ./$program "$input" >> $out_file
	echo -e  >> $out_file
done