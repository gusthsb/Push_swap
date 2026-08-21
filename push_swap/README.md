# Push_swap

*This project has been created as part of the 42 curriculum by gustde-s, mamatos-*

## Description

Push_swap is a 42 School algorithmic complexity project that challenges you to sort a stack of integers using only two stacks (A and B) and a limited set of operations. The core objective is to generate the **smallest possible sequence of operations** that sorts the input in ascending order.

This implementation goes beyond basic requirements by featuring:
- **Four distinct sorting strategies** with different algorithmic complexities (O(n²), O(n√n), O(n log n), and adaptive)
- **Automatic strategy selection** based on input disorder level
- **Benchmark mode** with detailed performance metrics
- **Circular doubly-linked list** data structure for efficient stack manipulation

## Instructions

### Compilation

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

**Compilation flags**: `-Wall -Wextra -Werror` (enforced by 42 Norm)

### Execution

#### Basic Usage

```bash
# Default behavior (uses adaptive strategy)
./push_swap 5 4 3 2 1

# Force a specific strategy
./push_swap --simple 5 4 3 2 1      # O(n²)
./push_swap --medium 5 4 3 2 1      # O(n√n)
./push_swap --complex 5 4 3 2 1     # O(n log n)
./push_swap --adaptive 5 4 3 2 1    # Automatic selection (default)

# No arguments → exit silently
./push_swap
```

#### Benchmark Mode

```bash
# Enable benchmark output to stderr (operations still on stdout)
./push_swap --bench --simple 5 4 3 2 1
./push_swap --bench --complex 100 numbers...

# View only benchmark metrics (redirect stdout to dev/null)
./push_swap --bench --adaptive $ARG > /dev/null 2>&1
```

#### Verification and Testing

```bash
# Verify with the provided checker
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

# Test with randomly generated numbers
ARG=$(shuf -i 1-500 -n 100); ./push_swap $ARG | ./checker_linux $ARG

# Pipe benchmark to checker while saving metrics
ARG="4 67 3 87 23"; ./push_swap --bench --complex $ARG 2> bench.txt | ./checker_linux $ARG
```

### Command-Line Flags

| Flag | Behavior |
|------|----------|
| `--simple` | Forces O(n²) selection sort strategy |
| `--medium` | Forces O(n√n) chunk-based strategy |
| `--complex` | Forces O(n log n) radix sort strategy |
| `--adaptive` | Auto-selects strategy based on disorder (default if no flag) |
| `--bench` | Enables benchmark mode; outputs statistics to stderr |

### Benchmark Output Example

```
[bench] disorder: 42.56%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 847
[bench] sa: 0 sb: 0 ss: 0 pa: 400 pb: 400
[bench] ra: 23 rb: 15 rr: 9 rra: 0 rrb: 0 rrr: 0
```

### Error Handling

The program displays `Error` to stderr and exits for:
- Non-integer arguments (e.g., `"abc"`)
- Integers outside the `int` range (< -2,147,483,648 or > 2,147,483,647)
- Duplicate values in the input
- Malformed input

## Technical Details

### Data Structure

**Circular Doubly-Linked List** is used for both stacks:
- Each node stores: `value`, `index`, and pointers (`next`, `prev`)
- Enables O(1) rotations in both directions
- Index assignment maps values to ranks (0 to n-1), essential for radix sort

### Operations

The following 11 operations are available (in the Push_swap language):

| Operation | Effect |
|-----------|--------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push top of B to top of A |
| `pb` | Push top of A to top of B |
| `ra` | Rotate A upward (top → bottom) |
| `rb` | Rotate B upward (top → bottom) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Rotate A downward (bottom → top) |
| `rrb` | Rotate B downward (bottom → top) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

### Disorder Metric

**Disorder** is a value between 0.0 and 1.0 that measures how unsorted the input is:

```
disorder = (number of inversions) / (total possible pairs)
         = (pairs where a[i] > a[j] and i < j) / (n × (n-1) / 2)
```

- Perfectly sorted array: disorder = 0.0
- Reverse-sorted array: disorder = 1.0 (100% inverted)
- Disorder is computed **before any operations** begin

## Algorithm Justification

### 1. Simple Strategy — O(n²) Selection Sort Adaptation

**How it works:**
- Find minimum element in stack A using comparisons (by index)
- Rotate it to the top
- Push to stack B
- Repeat until A is empty
- Push all elements back from B to A (now sorted)

**Complexity Analysis:**
- Finding min: O(n)
- Rotating to top: O(n) rotations in worst case
- Total: n iterations × O(n) per iteration = **O(n²) operations**

**Why this strategy?**
- Extremely simple logic, easy to verify correctness
- Nearly-sorted inputs require very few operations
- Minimal overhead for small datasets

**Threshold:** disorder < 20% (input is already mostly sorted)

**Example performance:**
- 5 numbers: ~15 operations
- 100 numbers (low disorder): ~1500 operations

### 2. Medium Strategy — O(n√n) Chunk-Based Sorting

**How it works:**
1. Calculate chunk size: `k = √n` (e.g., √100 = 10)
2. Divide range into chunks: [0..k-1], [k..2k-1], ..., [(√n-1)k..n-1]
3. Push elements in chunk order to B, rotating smaller elements down for efficient access
4. Push all elements back to A in reverse order of chunks

**Complexity Analysis:**
- √n chunks, each containing ~√n elements
- Processing each chunk: O(n) rotations over √n chunks
- Total: **O(n√n) operations**

**Why this strategy?**
- Significantly fewer operations than simple sort for moderately chaotic inputs
- Avoids expensive bit-manipulation of radix sort
- √n scaling provides smooth performance transition

**Threshold:** 20% ≤ disorder < 50% (moderately unsorted)

**Example performance:**
- 100 numbers (medium disorder): ~800 operations
- 500 numbers (medium disorder): ~7000 operations

### 3. Complex Strategy — O(n log n) Radix Sort (LSD)

**How it works:**
1. Map values to indices (ranks 0 to n-1) for bit operations
2. For each bit position (LSB to MSB, total log₂(n-1) bits):
   - Partition: elements with bit=0 go to B, bit=1 stay in A
   - Rotate A back to original relative order
3. After all bits processed, A contains sorted elements

**Complexity Analysis:**
- log₂(n) passes through the array
- Per pass: O(n) push/rotate operations
- Total: **O(n log n) operations**

**Why this strategy?**
- Best asymptotic complexity for large, highly unsorted inputs
- Index-based (not value-based), so works with any integer range
- Radix sort is deterministic: no randomness, consistent operation count

**Threshold:** disorder ≥ 50% (highly chaotic input)

**Example performance:**
- 100 numbers (high disorder): ~700 operations
- 500 numbers (high disorder): ~5500 operations

### 4. Adaptive Strategy — Hybrid Approach

**How it works:**
1. Measure disorder of input **before sorting begins**
2. Select optimal strategy based on disorder thresholds:
   - **disorder < 20%** → Simple (O(n²))
   - **20% ≤ disorder < 50%** → Medium (O(n√n))
   - **disorder ≥ 50%** → Complex (O(n log n))
3. Execute selected strategy

**Threshold Justification:**
- **20%:** Empirically, selection sort outperforms radix sort for low chaos
- **50%:** Radix sort becomes superior for truly random or reverse-ordered inputs

**Why adaptive?**
- No single algorithm dominates all input patterns
- By analyzing disorder first, we choose the algorithm most likely to minimize operation count
- Provides near-optimal performance across the entire input spectrum


*All benchmarks are verified using the provided `checker_linux` binary during evaluation.*

## Resources

### Documentation & References

- [42 School Push_swap Subject]
- [Radix Sort — Brilliant.org](https://brilliant.org/wiki/radix-sort/)
- [Selection Sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Linked Lists — GeeksforGeeks](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
- [Sorting Algorithm Visualizer](https://github.com/AlgoVisualizer/AlgoVisualizer)

### Use of AI in This Project

AI tools (Claude/Gemini) were used for:

- **Algorithm exploration**: Comparing radix sort, merge sort, and chunk-based approaches
- **Debugging**: Identifying edge cases in chunk sorting and rotation logic in general
- **Documentation**: Helping to struct the README
- **Code review**: Memory leak detection

**Important note**: All code was written, tested, and thoroughly understood by both team members. AI was used as a learning assistant and brainstorming tool, not as a code generator. Every algorithm was manually implemented and tested against edge cases.

## Team Contributions

- **gustde-s**: Algorithm implementation (simple, medium), debugging, testing), Data structure design, benchmark mode, documentation
- **mamatos-**: Algorithm implementation (simple, radix sort), disorder calculate, print operations, utils for the functions
