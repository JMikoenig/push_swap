#!/bin/bash

while :
	do
		ARG=$(seq 1 500 | sort -R | tr '\n' ' ')
		RES=$(./push_swap $ARG | wc -l)
		if [ $((RES)) > 5500 ]
		then
			echo $RES
		fi
	done
