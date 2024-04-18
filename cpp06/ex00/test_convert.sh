#!/bin/bash

# out file
out_file="test_convert_output.txt"

#test inputs
inputs=(
	" "
	"\n"
	"\t"
	"-."
	"+."
	".+"
	".-"
	".e-1"
	"e"
	"1e"
	"1.0e"
	"1.0e-1"
	"42.f"
	"1.0e-0000000000000000000000000000001"
	" "
	"     "
	"-f"
	"f"
	""
	"+nan"
	"-inff"
	".f"
	"infff"
	"
	"
	"1.0g"
	"1..0"
	"."
	"00000000000000000000000000000000000000000000001"
	","
	"1fg"
	"3.0F"
	"3.0f"
	"1.7e+38f"
	"1.7e+38F"
	"9223372036854775807"
	"9223372036854775808"
	"99223372036854775808"
	"3"
	"0"
	"nan"
	"-"
	"65"
	"42.0f"
	"+"
	"+-"
	"2147483647"
	"2147483648"
	"-2147483648"
	"-2147483649"
	"-2147483650"
	"yayaa cenas"
	"123123"
	"1.7e+38"
	"1.7e-38F"
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
