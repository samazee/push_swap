*This project has been created as part of the 42 curriculum by azgor.*

## Description

Push_swap is a sorting algorithm project that requires arranging a stack of integers in ascending order using only a restricted set of operations on two stacks (a and b). The goal is to minimize the number of operations required to sort the input.

### Game Rules

- Stack **a** contains a random permutation of non-duplicate integers
- Stack **b** starts empty
- Operations allowed:
  - `sa`, `sb`, `ss`: swap the first two elements of stack a, b, or both
  - `pa`, `pb`: push the top element from one stack to the other
  - `ra`, `rb`, `rr`: rotate stack a, b, or both (first element becomes last)
  - `rra`, `rrb`, `rrr`: reverse rotate stack a, b, or both (last element becomes first)

### Algorithm

The implementation uses the **radix sort** algorithm with binary representation of indexed values. This allows sorting in O(n * log(n)) time complexity.

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./push_swap [list of integers]
```

### Examples

```bash
./push_swap 5 2 3 1 4
./push_swap "3 1 4 1 5 9 2 6"
```

### Clean

```bash
make clean    # removes object files
make fclean   # removes object files and executable
make re       # recompiles the project
```

## Resources

- [Push_swap - 42 Documentation](https://github.com/42Schoolsubjects/push_swap)
- [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Binary Number System](https://en.wikipedia.org/wiki/Binary_number)
