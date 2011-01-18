#!/bin/bash
	`gcc hellolong.c -o helloc.out -std=c99`
	time ./helloc.out &
	PID=`ps -aef | grep "$PROGRAM" | grep -v grep | awk '{print $2}'`
	j=1;
	while [[$PID]];do
		taskset -c -p $((j)) $PID 
#		j=$((j^1));
		done

	time ./helloc.out

rm helloc.out
