# PUSH SWAP

## Description
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.

## Challenge
To produce an algorithm which outputs instructions, to sort data. In this project, we must produce two programs, `push_swap` and `checker`. `push_swap` displays on `stdout`, instructions to sort data in a stack. `checker` reads `stdin` and ensures that instructions are valid, and that they sort the data. The two programs can be used together, see below.

The game is composed of 2 stacks named **a** and **b**.</br>
To start with:</br>
**a** contains a random number of either positive or negative numbers without any duplicates.</br>
**b** is empty </br>
The goal is to sort in ascending order numbers into stack a.
To do this you have the following operations at your disposal:

- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : sa and sb at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : rra and rrb at the same time.

## Using the project
To compile, run `make`. This will compile two programs; `push_swap` and `checker`. Both programs take numbers as an argument.

### push_swap

To use `push_swap`, we execute it with numbers as an argument(s). It is versatile and all of the following are valid as input:

```
$> ./push_swap 1 0 2 13 -45
```
```
$> ./push_swap "1 0 2 13 -45"
```
```
$> ./push_swap 1 0 "2" 13 "-45"
```

`push_swap` would return on `stdout` the following:
```
./push_swap 1 0 2 13 -45
sa
ra
ra
ra
ra
pb
pa
```

### checker
To use `checker`, we execute it with numbers as an argument(s) in exactly the same format as push_swap above. `checker` will then wait to receive instructions, one per line, on `stdin`.

In the following example, we give 1, 0 and 2 as an unsorted list. `checker` will wait to receive valid instruction(s) sa. We can simulate EOF with Ctrl + d. `checker` should display `OK` to indicate the list is sorted, or `KO` otherwise.

```
$> ./checker 1 0 2
sa
OK
```

### push_swap AND checker

```
$> ARG="1 0 2 -9 3 8"; ./push_swap $ARG | ./checker $ARG
OK
$> ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
OK
```