#!/bin/bash

# out file
out_file="test_RPN_output.txt"
program="RPN"
#test inputs
inputs=(
	" "
    "hello potato"
    "3   5   +    /     -"
)

#remove previous outfile if it exists
rm -f $out_file

#loop through inputs and run
for input in "${inputs[@]}"
do
	echo -e "input is: \"$input\"\n"  >> $out_file
    ./$program "$input" >> $out_file
	echo -e "\n"  >> $out_file
done
