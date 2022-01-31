#!/bin/bash

# CONFIG
INPUT_PROGRAM="./test_maker.py"
TO_TEST="./build/11990_Dynamic_Inversion"
seed_start=1
seed_end=100

done=false
for number in $(seq $seed_start $seed_end)
do
    if [[ $done == true ]]; then
        break
    fi
    
    # gen files
    $INPUT_PROGRAM $number

    # read to arrays
    OUTPUT_CORRECT=($(cat OUTPUT.txt))
    OUTPUT_TEST=($(cat INPUT.txt | $TO_TEST))

    # compare two arrays
    for num2 in $(seq 0 ${#OUTPUT_CORRECT[@]}); do
        if [[ ${OUTPUT_TEST[$num2]} -ne ${OUTPUT_CORRECT[$num2]} ]]; then
            echo -e "\e[1;31mFor seed \e[1;33m${number}\e[1;31m an error occurred for input:\e[1;37m\n$(cat INPUT.txt)\e[0;37m"
            echo -e -n "Expected:\n\t${OUTPUT_CORRECT[@]}\nRecieved:\n\t"
            for num3 in $(seq 0 ${#OUTPUT_CORRECT[@]}); do
                if [[ ${OUTPUT_TEST[$num3]} == ${OUTPUT_CORRECT[$num3]} ]]; then
                    echo -e -n "\e[1;32m"
                else
                    echo -e -n "\e[1;31m"
                fi
                echo -e -n "${OUTPUT_TEST[num3]}\e[0;37m "
            done
            # to add a new line
            echo 
            done=true
            break
        fi
    done
done
if [[ $done == false ]]; then
    echo -e "\e[1;32mYour program works for seeds \e[1;33m<${seed_start}, ${seed_end}>\e[0;37m"
fi
