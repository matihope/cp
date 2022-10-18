#!/bin/bash

# CONFIG
TO_TEST="./build/lab1"
start_num=0
end_num=15
path="studia/wdp/testy_lab1"

done=false
for number in $(seq $start_num $end_num)
do
    if [[ $done == true ]]; then
        break
    fi

    # read to arrays
    OUTPUT_CORRECT=($(cat ${path}/dzielny${number}.out))
    OUTPUT_TEST=($(cat ${path}/dzielny${number}.in | $TO_TEST))

    # compare two arrays
    for num2 in $(seq 0 ${#OUTPUT_CORRECT[@]}); do
        if [[ ${OUTPUT_TEST[$num2]} -ne ${OUTPUT_CORRECT[$num2]} ]]; then
            echo -e "\e[1;31mFor test number \e[1;33m${number}\e[1;31m an error occurred"
            echo -e -n "Expected:\n\t${OUTPUT_CORRECT[@]}\nReceived:\n\t"
            for num3 in $(seq 0 ${#OUTPUT_CORRECT[@]}); do
                if [[ ${OUTPUT_TEST[$num3]} == ${OUTPUT_CORRECT[$num3]} ]]; then
                    echo -e -n "\e[1;32m"
                else
                    echo -e -n "\e[1;31m"
                fi
                echo -e -n "${OUTPUT_TEST[num3]}\e[0;37m "
            done
            echo
            done=true
            break
        fi
    done
done
if [[ $done == false ]]; then
    echo -e "\e[1;32mYour program works for tests numbered \e[1;33m<${start_num}, ${end_num}>\e[0;37m"
fi
