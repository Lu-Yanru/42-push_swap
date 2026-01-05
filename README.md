*This project has been created as part of the 42 curriculum by yanlu.*

# Description
This project implements algorithms to sort data in a stack using a limited set of operations, aiming to achieve the lowest possible number of actions.

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
  - If there are 2 elements: `sa`.
  - If there are 3 elements:
    - `1 3 2` -> `rra sa`
    - `2 1 3` -> `sa`
    - `2 3 1` -> `rra`
    - `3 1 2` -> `ra`
    - `3 2 1` -> `ra sa`
  - If there are 4 - 5 elements: `pb` twice. Sort `stack a` and `stack b` respectively using the method above. Then rotate `stack a` until the top of `stack b` is at the correct position (between top and bottom of `a`). Then `pa`. Do this until `stack b` is empty.
  - If there are more than 5 elements:

# Instructions
Compile the program by running:

    make

Run the program by supplementing the executable file with a set of integers. This will give you a list of actions taken to sort the stack:

    ./push_swap 2 1 3 6 5 8

To run the program with numbers from a file instead of inputing the numbers directly from the command line:



To calculate how many steps are taken to sort the stack, run:

    ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

To use the checker the result of the sorting, run the following command. It should display "OK" if `stack a` is correctly sorted and `stack b` is empty, "KO" otherwise.

    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

In case of error (e.g. the input other symbols than integers, the input numbers are not unique), the program displays "Error" on the standard error. This can be checked by running:

    ./push_swap $ARG 2 > error.txt

# Resources
- [Big-O cheat sheet](https://www.bigocheatsheet.com/)
- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
https://github.com/Niimphu/push_swap_visualiser
