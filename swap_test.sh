#!/bin/bash

read -p "Enter no. of values to sort: " MAX
if [[ $MAX = "" ]]; then MAX=100; fi
read -p "Enter minimum range: " RANGEMIN
if [[ $RANGEMIN = "" ]]; then RANGEMIN=-100; fi
read -p "Enter maximum range: " RANGEMAX
if [[ $RANGEMAX = "" ]]; then RANGEMAX=100; fi
read -p "Enter number of tests to conduct: " TESTS
if [[ $TESTS = "" ]]; then TESTS=5; fi
make re
make bonus
cc random_number_generator.c
i=1
while [ $TESTS -gt 0 ]
do
clear
printf "Test $i"
read
ARGS=$(./a.out $MAX $RANGEMIN $RANGEMAX | tr -d '\0')
printf "Numbers to be sorted: %s\n" "$ARGS"
printf "Testing with checker_linux"
read
valgrind ./push_swap $ARGS | ./checker_linux $ARGS
printf "Testing with own checker"
read
valgrind ./push_swap $ARGS | ./checker $ARGS
read
printf "Number of instructions: %s\n" "$(./push_swap $ARGS | wc -l)"
TESTS=$((TESTS-1))
i=$((i+1))
done
#make re
#shopt -s extglob
#cc ./!(random_number_generator).c -o push_swap
#printf "Numbers to be sorted: "
#printf '\n'
#read enter
#printf "%s\n" "$ARG"
#printf '\n'
#printf "Press enter to test"
#read
#printf '\n'
#./push_swap $ARG
#printf '\n'

#printf "Press enter to test with checker_linux"
#read enter
#printf "Testing with checker_linux\n"
#printf "./push_swap $ARG | ./checker_linux $ARG\n"
#./push_swap $ARG | ./checker_linux $ARG
#printf "Press enter to test with own checker"
#read enter
#printf "Testing with own checker\n"
#make bonus
#./push_swap $ARG | ./checker $ARG
#printf "Total number of instructions = %s\n" $(./push_swap $ARG | wc -l)
printf "\nPress enter to fclean"
read enter
make fclean
#rm a.out
