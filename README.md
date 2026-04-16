*This project has been created as part of the 42 curriculum by <mvoskany>, <nhovhiky>.*

# Push_swap

## Description

Push_swap is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using two stacks (A and B) and a limited set of operations, while minimizing the total number of operations used.

The program receives a list of integers as arguments, and outputs the sequence of operations needed to sort stack A in ascending order (smallest at the top).

Available operations:
- `sa`, `sb`, `ss` — swap top two elements
- `pa`, `pb` — push top element from one stack to another
- `ra`, `rb`, `rr` — rotate (top goes to bottom)
- `rra`, `rrb`, `rrr` — reverse rotate (bottom goes to top)

---

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./push_swap [strategy] [numbers]
```

**Strategy flags (optional):**
- `--simple` — forces O(n²) algorithm (Insertion Sort)
- `--medium` — forces O(n√n) algorithm (Chunk Sort)
- `--complex` — forces O(n log n) algorithm (Radix Sort)
- `--adaptive` — selects strategy automatically based on disorder (default)

**Benchmark flag (optional):**
- `--bench` — displays sorting statistics to stderr after sorting

### Examples

```bash
# Sort with default adaptive strategy
./push_swap 4 67 3 87 23

# Force simple O(n²) strategy
./push_swap --simple 5 4 3 2 1

# Verify result with checker
./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23

# Count operations
./push_swap 4 67 3 87 23 | wc -l

# Run with benchmark (stats go to stderr)
./push_swap --bench 4 67 3 87 23

# Save benchmark stats to file
./push_swap --bench 4 67 3 87 23 2>bench.txt 1>/dev/null && cat bench.txt

# Test with random numbers
ARGS=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
./push_swap $ARGS | ./checker_linux $ARGS
```

### Error handling

```bash
./push_swap 1 two 3     # Error (not an integer)
./push_swap 1 1 2       # Error (duplicate)
./push_swap 2147483648  # Error (out of int range)
```

---

## Algorithms

### Disorder Metric

Before sorting, the program computes a disorder value between 0 and 1. It counts all pairs (i, j) where i < j but arr[i] > arr[j] (inversions), divided by total pairs. A disorder of 0 means already sorted, 1 means fully reversed.

### Simple — O(n²) — Insertion Sort

Finds the minimum element in stack A, rotates it to the top using `ra` or `rra` (whichever is shorter), then pushes it to B with `pb`. Repeats until A is empty. B fills in ascending order. Finally, all elements are pushed back to A with `pa`, resulting in ascending order (minimum at top).

**Why O(n²):** For each of n elements, we scan the entire remaining stack to find the minimum — n iterations × n scan = n².

### Medium — O(n√n) — Chunk Sort

Normalizes values to indices 0..n-1, then divides the range into √n chunks. Pushes elements belonging to each chunk from A to B, using `rb` to partially sort within chunks. After all chunks are in B, extracts elements back to A by finding the maximum in B each time.

**Why O(n√n):** √n chunks × n operations per chunk = n√n.

### Complex — O(n log n) — Radix Sort (LSD)

Normalizes values to indices 0..n-1. Sorts by each bit from least significant to most significant (log n bits total). For each bit: if the bit is 0, pushes element to B; if 1, rotates to bottom of A. Then pushes all elements back from B to A.

**Why O(n log n):** log n bit passes × n operations per pass = n log n.


### Adaptive — Custom Strategy

Selects algorithm based on disorder value:
- disorder < 20.00% (low) → Simple O(n²) — few inversions, cheap to fix
- 20.00% ≤ disorder < 50.00% (medium) → Medium O(n√n)
- disorder ≥ 50.00% (high) → Complex O(n log n) — heavily shuffled

**Rationale for thresholds:** At low disorder, most elements are already in place. An O(n²) algorithm is fast in practice because it does very few rotations. At high disorder, the overhead of O(n²) becomes unacceptable and Radix Sort's guaranteed O(n log n) is preferred.

---

## Performance

| Input size | Minimum | Good | Excellent |
|------------|---------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Bonus — Checker

### Description

The `checker` program reads a sequence of operations from stdin and verifies whether they correctly sort the stack. This allows you to validate the output of `push_swap` or any other sequence of operations.

### Compilation

```bash
make bonus
```

### Usage

```bash
./checker [numbers]
```

The checker takes the same argument format as `push_swap`. It reads operations from stdin line by line, executes them on the stack, and prints the result.

### Examples

```bash
# Check that push_swap output is valid
./push_swap 3 2 1 0 | ./checker 3 2 1 0
# OK

# Manual operations
echo -e "rra\npb\nsa\nrra\npa" | ./checker 3 2 1 0
# OK or KO

# Error cases
./checker 3 2 one 0
# Error (not an integer)

./checker "" 1
# Error (empty argument)
```

### Output

- `OK` — stack A is sorted in ascending order and stack B is empty
- `KO` — operations did not sort the stack correctly
- `Error` (to stderr) — invalid arguments or unknown operation

---

## Resources

- [Big-O Notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Insertion Sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Sorting Algorithms Visualized](https://visualgo.net/en/sorting)

### AI Usage

Claude (Anthropic) was used during this project for:
- Explaining algorithmic concepts (Big-O, insertion sort, insertion sort, radix sort)
- Discussing trade-offs between sorting strategies
- Final tuning

---

## Contributors

| Login | Contributions |
|-------|--------------|
| mvoskany | Parsing, medium algorithm, complex algorithm (Radix Sort), stack operations, project architecture, bonus, Makefile |
| nhovhiky | Simple algorithm (Selection Sort), disorder metric, stack operations, testing, norminette, README |
