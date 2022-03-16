# PUSH_SWAP

This project aims to introduce you to the world of algorithms. The subject indeed asks you to think and create your own algorithm to sort a list of integers passed as arguments
using `stacks`. You can use only two stacks `stack_a` and `stack_B`. The subject seems very easy, but there are two big obstacles: the very first problem is that you can use
only 11 functions (that you'll define in your program) between the two stacks:

`sa (swap a)`: Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

`sb (swap b)`: Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

`ss` : sa and sb at the same time.

`pa (push a)`: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

`pb (push b)`: Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

`ra (rotate a)`: Shift up all elements of stack a by 1.
The first element becomes the last one.

`rb (rotate b)`: Shift up all elements of stack b by 1.
The first element becomes the last one.

`rr` : ra and rb at the same time.

`rra (reverse rotate a)`: Shift down all elements of stack a by 1.
The last element becomes the first one.
`
rrb (reverse rotate b)`: Shift down all elements of stack b by 1.
The last element becomes the first one.

`rrr` : rra and rrb at the same time.

The other (biggest) problem, is that the subject asks you to create an algorithm that'll `sort x numbers in less than x instructions`. That's the reason why i graded 86/100:
my algorithm works fine but it sorts 100 numbers in 700/750 instructions (less than 700 instructions for max grade) and 500 numbers in 7500 instructions (less than 5500
instructions for max grade). I'm not 100% satisfied for this reason, but I aim to get back to this project later to improve my grade.

![push_swap](https://user-images.githubusercontent.com/99179085/158694526-0f43839c-f239-4944-9d22-8e819e0e9d69.png)
