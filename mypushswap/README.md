*This activity has been created as part of the 42 curriculum by nlaine, alexdos.*

# push_swap

## Description

`push_swap` is a sorting program written in C. Given a list of integers, it computes and prints the **shortest possible sequence of stack operations** that sorts those integers in ascending order, using only two stacks (`a` and `b`) and a restricted instruction set.

The project is a hands-on exploration of **algorithmic complexity**: the same data can be sorted with very few or very many operations depending on the strategy chosen. To highlight this, the program embeds four distinct sorting strategies and can pick one automatically based on how disordered the input is.

The data is held in a **doubly linked list** (`t_list`), where each node stores its value, a precomputed `rank`, and pointers to its previous and next neighbours.

## Instructions

### Compilation

```bash
make        # builds the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # full rebuild
```

The project compiles with `cc` using the flags `-Wall -Wextra -Werror` and complies with the 42 Norm.

### Usage

```bash
./push_swap [strategy] <list of integers>
```

The list of integers is passed as program arguments (the first integer is the top of stack `a`). An optional strategy selector can be placed before the numbers:

| Flag          | Strategy                          | Complexity (in operations) |
|---------------|-----------------------------------|----------------------------|
| `--simple`    | Forces the baseline algorithm     | O(n²)                      |
| `--medium`    | Forces the chunk-based algorithm  | O(n√n)                     |
| `--complex`   | Forces the radix algorithm        | O(n log n)                 |
| `--adaptive`  | Picks a strategy from the disorder| varies                     |
| `--bench`     | Prints benchmark metrics to stderr | —                         |

If no selector is given, `--adaptive` is used. If no argument is given at all, the program prints nothing and exits.

### Examples

```bash
$> ./push_swap 2 1 3 6 5 8
ra
pb
ra
...

$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./fedora_checker $ARG
OK

$> ./push_swap --adaptive 0 one 2 3
Error
```

On invalid input (non-integer arguments, values outside the `int` range, or duplicates), the program writes `Error\n` to the standard error.

## Strategies and algorithms

The program must justify the complexity of each strategy **in the push_swap operation model** — that is, the cost measured in the number of generated operations, not the textbook complexity of an array-based sort.

### Disorder metric

Before sorting, the program computes a **disorder** value between 0 and 1. It counts, over all pairs of elements, how many appear out of order (a larger value before a smaller one), divided by the total number of pairs. A disorder of 0 means already sorted; a value near 1 means strongly reversed. This metric drives the adaptive strategy.

### 1. Simple — O(n²)

A selection-style sort: repeatedly find the minimum of stack `a`, rotate it to the top, and push it to `b`. Once `a` is reduced to three elements, it is sorted directly, then everything is pushed back to `a`. Few helpers, simple to reason about, but the operation count grows quadratically.

### 2. Medium — O(n√n)

A chunk-based sort. Elements are first ranked, then pushed to `b` in blocks of roughly √n consecutive ranks. Each value is brought to `b` either by rotating or reverse-rotating, whichever is closer. Once all values are in `b`, they are pushed back to `a` in descending rank order, again choosing the cheaper rotation direction.

### 3. Complex — O(n log n)

A radix sort on the **ranks** of the elements. Working bit by bit, each pass sends a value to `b` if the current bit is 0 and rotates it in `a` if the bit is 1, then pushes everything back. The number of passes equals the number of bits needed to represent the largest rank, giving the O(n log n) behaviour.

### 4. Adaptive — learner's design

The default strategy. It first handles tiny inputs (≤ 3 and ≤ 5 elements) with dedicated routines, then measures the disorder of the input and selects:

- **disorder < 0.2** → simple strategy
- **0.2 ≤ disorder < 0.5** → medium strategy
- **disorder ≥ 0.5** → complex strategy

The thresholds reflect that nearly-sorted inputs are cheapest to finish with a light algorithm, while strongly disordered inputs benefit from the radix approach.

## Project structure

| Component       | Responsibility                                              |
|-----------------|-------------------------------------------------------------|
| Parsing         | Argument validation, flag detection, list construction, memory cleanup |
| Stack operations| `sa sb ss pa pb ra rb rr rra rrb rrr` and their primitives  |
| Sorting         | The four strategies and their helpers                       |
| Benchmark       | Disorder, strategy name, and per-operation counters on stderr |
| Main            | Orchestration: parse → check → sort → free                  |

## Contributions

- **nlaine** — Parsing: argument validation (format, integer overflow, duplicates), flag detection, doubly linked list construction, and memory management.
- **alexdos** — Sorting algorithms (simple, medium, complex, adaptive), stack operations, benchmark mode, and main orchestration.

*Both members understand and can defend the full codebase.*

## Resources

- Radix sort and selection sort references for the strategy implementations.
- 42 documentation on the Norm and project requirements.

### Use of AI

AI (Claude) was used as a **Socratic tutor**. Rather than producing ready-made code, it guided us through the reasoning with leading questions: identifying the error cases to handle (invalid characters, misplaced signs, overflow, duplicates), choosing return-value conventions, designing the linked-list construction, and locating bugs such as the memory leak on early return. All code was written by the author and is understood.
