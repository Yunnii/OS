#!/bin/bash
	gcc hellolong.c -o helloc.out					#
	time ./helloc.out &						#
	PIDold=`ps -a | grep "helloc.out" | awk '{print $1}'` 		#
	PIDnew=$PIDold							#
	j=1;								#
	while [ $PIDold = $PIDnew ];do					#
		echo "x", `ps -a | grep "helloc.out" | awk '{print $1}'`, "x";
		taskset -p $j $PID > /dev/null				#
		j=$(($j^3));						#
		if [[ $PID!=`ps -a | grep "helloc.out" | awk '{print $1}'` ]];then #
			break;						#
		fi							#
		done								#
	time ./helloc.out						#
	rm helloc.out							#
