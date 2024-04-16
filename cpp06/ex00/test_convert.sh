#!/bin/bash

# out file
out_file="test_convert_output.txt"

#test inputs
inputs=(
	"3"
	"0"
	"nan"
	"-"
	"65"
	"42.0f"
	"+"
	"2147483647"
	"2147483648"
	"-2147483648"
	"-2147483649"
	"yayaa cenas"
	"123123"
	"1.7e+38"
	"1.7e+308"
	"+1.7e+308"
	"-1.7e+308"
	"-1.7e+3008"
	"inf"
	"+inf"
	"-inf"
	"-nan"
	"+inff"
	"3a"
	"1.7e+38e"
	"\\"
	"\\\\"
)

#remove previous outfile if it exists
rm -f $out_file

#loop through inputs and run
for input in "${inputs[@]}"
do
	echo -e "input is: \"$input\"\n"  >> $out_file
    ./convert "$input" >> $out_file
	echo -e "\n"  >> $out_file
done
