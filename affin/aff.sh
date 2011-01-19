#!/bin/bash
        gcc hellolong.c -o helloc.out                                                   #
        time ./helloc.out &                                                                             #
        PID=`ps -a | grep "helloc.out" | awk '{print $1}'`              #
        j=1;    #
        while [  -z `ps -a | grep "helloc.out" | awk '{print $1}'` ]; do                                        #
                taskset -p $j $PID > /dev/null                                          #
                j=$(($j^1));                                                                            #
        done                                                                                                    #
        time ./helloc.out                                                                               #
        rm helloc.out                                                                                   #

