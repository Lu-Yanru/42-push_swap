*This project has been created as part of the 42 curriculum by yanlu.*

# Description
This project implements an algorithm to sort data in a stack using a limited set of operations, aiming to achieve the lowest possible number of actions.

The program receives a `stack a` containing a random number of unique negative and/or positive integers and an empty `stack b`. The goal is to sort the numbers in `stack a` in ascending order using `stack b` to store data temporarily.

This project is written in C.

## Operations
The following operations can be used:

- **sa (swap a)**: Swap the first 2 elements at the top of `stack a`. Do nothing if there is only one element or none.
- **sb (swap b)**: Swap the first 2 elements at the top of `stack b`. Do nothing if there is only one element or none.
- **ss** : `sa` and `sb` at the same time.
- **pa (push a)**: Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
- **pb (push b)**: Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
- **ra (rotate a)**: Shift up all elements of `stack a` by 1. The first element becomes the last one.
- **rb (rotate b)**: Shift up all elements of `stack b` by 1. The first element becomes the last one.
- **rr** : `ra` and `rb` at the same time.
- **rra (reverse rotate a)**: Shift down all elements of `stack a` by 1. The last element becomes the first one.
- **rrb (reverse rotate b)**: Shift down all elements of `stack b` by 1. The last element becomes the first one.
- **rrr** : `rra` and `rrb` at the same time.

## Benchmarks
- < 700 operations for 100 random numbers
- <= 5500 operations for 500 random numbers
- < 12 operations for 5 numbers
- <= 2 operations for 3 numbers
- Do nothing for a sorted array

## Algorithms
- Check if `stack a` is already sorted. If yes, do nothing.
- Check how many elements are in `stack a`.
  - If there are 2 elements: `ra`.
  - If there are 3 elements:
    - `1 3 2` -> `rra sa`
    - `2 1 3` -> `sa`
    - `2 3 1` -> `rra`
    - `3 1 2` -> `ra`
    - `3 2 1` -> `ra sa`
  - If there are more than 3 elements:
    - Step 1: Find the [longest increasing subsequence (LIS)](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) in `stack a`.
    - Step 2: Calculate the cost of putting each non-LIS numbers in `stack a` into its correct position in `stack b`, so that the numbers in `stack b` are in descending order.
    - Step 3: Push the number with the lowest cost to `stack b`. Repeat step 2 and 3 until all non-LIS numbers are in `stack b`. Or if the length of LIS is less than 3, repeat step 2 and 3 until there are 3 numbers left in `stack a`.
    - Step 4: If the length of LIS is less than 3, sort `stack a` using the method above. Otherwise `stack a` should already be sorted.
    - Step 5: Calculate the cost of putting each numbers in `stack b` into its correct position in `stack a`.
    - Step 6: Push the number with the lowest cost from `stack b` to `stack a`. Repeat step 5 and 6 until `stack b` is empty.
    - Step 7: Rotate `stack a` until the smallest number is on the top.

## Checker
The checker confirms the result of the sorting. It displays "OK" if `stack a` is correctly sorted and `stack b` is empty, "KO" otherwise.

# Instructions
Compile the program by running:

    make

Run the program by supplementing the executable file with a set of integers. This will give you a list of actions taken to sort the stack:

    ./push_swap 2 1 3 6 5 8

To test the program with randomly generated numbers, use the `shuf` command. It shuffles a series of positive integers randomly:

    ARG=$(shuf -i 0-1000 -n 500); ./push_swap $ARG

To run the program with numbers from a file instead of inputing the numbers directly from the command line:

	./push_swap $(< test.txt)

To calculate how many steps are taken to sort the stack, run:

    ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

To use the checker, run the following command:

    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

In case of error (e.g. the input contains other symbols than integers, the input numbers are not unique), the program displays "Error" on the standard error. This can be checked by running:

    ARG="0 one 2 3"; ./push_swap $ARG 2 > error.txt

To see the exit code:

	echo $?

# Resources
- [Big-O cheat sheet](https://www.bigocheatsheet.com/)
- [Sorting Algorithms Animations](https://www.toptal.com/developers/sorting-algorithms)
- [Algorithms for Competitive Programming tutorial Longest Increasing Subsequence](https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html)
- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
https://github.com/Niimphu/push_swap_visualiser
- [push_swap manual moves visualizer](https://phemsi-a.itch.io/push-swap)
- [Random number generator](https://numbergenerator.org/randomnumbergenerator/1-100#!numbers=500&low=1&high=500&unique=true&csv=&oddeven=&oddqty=0&sorted=false&addfilters=)
- [Doxygen style guide](https://micro-os-plus.github.io/develop/doxygen-style-guide/)
