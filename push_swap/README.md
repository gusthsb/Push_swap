## Autors

*This activity has been created as part of the 42 curriculum by gustde-s, mamatos-*

# Push_swap

## Description

Push_swap is a 42 School algorithmic project focused on sorting data using two stacks (A and B) with a limited set of operations. The goal is to sort a stack of integers in ascending order with the minimum number of operations possible.

This implementation goes beyond the basic requirements by providing **multiple sorting strategies** that can be selected via command-line flags, a **benchmark mode** for performance analysis, and an **adaptive strategy** that automatically chooses the best algorithm based on the input's disorder level.

The project uses a **circular doubly-linked list** as the underlying data structure for both stacks, allowing efficient rotation and manipulation operations.

## Instructions

### Compilation

The project includes a Makefile with the standard rules:

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

The Makefile compiles with `-Wall -Wextra -Werror` flags and does not relink.

### Execution

```bash
# Basic usage (defaults to adaptive strategy)
./push_swap 5 4 3 2 1

# Select a specific strategy
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Benchmark mode (prints statistics to stderr)
./push_swap --bench --simple 5 4 3 2 1
./push_swap --bench --complex 5 4 3 2 1

# Verify correctness with the checker
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

# Test with random numbers
ARG=$(shuf -i 1-500 -n 100); ./push_swap $ARG | ./checker_linux $ARG
```

### Available Flags

| Flag | Description |
|------|-------------|
| `--simple` | Uses O(n²) selection sort approach |
| `--medium` | Uses O(n√n) chunk-based sort approach |
| `--complex` | Uses O(n log n) radix sort approach |
| `--adaptive` | Automatically selects strategy based on input disorder (default) |
| `--bench` | Enables benchmark mode, printing statistics to stderr |

### Error Handling

The program handles the following error cases:
- Non-numeric parameters → prints `Error\n` to stderr
- Duplicate numeric parameters → prints `Error\n` to stderr
- Values outside INT range → prints `Error\n` to stderr
- No parameters → exits silently with code 0

## Resources

### Documentation and References
- [42 School - Push_swap Subject](https://github.com/42School)
- [Stack Operations - Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection Sort Algorithm](https://en.wikipedia.org/wiki/Selection_sort)
- [Circular Linked List - GeeksforGeeks](https://www.geeksforgeeks.org/circular-linked-list/)
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)

### Use of AI
AI tools (ChatGPT/Claude) were used during this project for the following tasks:
- **Brainstorming and algorithm design**: Exploring different sorting strategies and their trade-offs
- **Code review and debugging**: Identifying edge cases and potential memory leaks
- **Documentation**: Structuring the README and explaining algorithmic concepts
- **Performance optimization**: Suggestions for reducing operation counts

All final code was written, tested, and understood by both team members. AI was used as a learning aid, not as a code generator.

## Algorithm Justification

### Simple Strategy — O(n²) Selection Sort

**Approach**: Repeatedly finds the minimum element in stack A, rotates it to the top, and pushes it to stack B. After all elements are in B, pushes them back to A.

**Justification**: For very small inputs (n ≤ 5), the overhead of more complex algorithms is not worth it. Selection sort is simple, predictable, and easy to reason about. It performs well for nearly-sorted or very small datasets where the quadratic complexity is not a bottleneck.

**When to use**: Low disorder inputs (disorder < 20%), small datasets.

### Medium Strategy — O(n√n) Chunk Sort

**Approach**: Divides the input into chunks of size approximately √n. Elements are pushed to stack B in chunk order, with smaller elements rotated to the bottom of B for easier retrieval. Then elements are pushed back to A in descending order.

**Justification**: This strategy bridges the gap between simple and complex approaches. By dividing the problem into manageable chunks, it reduces the number of operations compared to pure selection sort while avoiding the bit-manipulation overhead of radix sort. The chunk size √n was chosen as it provides a good balance between the number of chunks and the size of each chunk.

**When to use**: Medium disorder inputs (20% ≤ disorder < 50%).

### Complex Strategy — O(n log n) Radix Sort

**Approach**: Uses the binary representation of element indexes. For each bit position (from LSB to MSB), elements with bit 0 are pushed to B, elements with bit 1 stay in A (rotated). After processing each bit, all elements are pushed back to A. This is a classic LSD (Least Significant Digit) radix sort adapted for stack operations.

**Justification**: Radix sort provides the best asymptotic complexity for large datasets. Since we can only compare and move elements between two stacks, the bit-based approach allows us to sort without explicit pairwise comparisons during the main loop. The number of passes is log₂(max_index), making it very efficient for 500 elements.

**When to use**: High disorder inputs (disorder ≥ 50%), large datasets.

### Adaptive Strategy

**Approach**: Calculates the input's disorder percentage (ratio of inversions to total possible pairs) and selects the most appropriate strategy:
- **Disorder < 20%** → Simple (O(n²))
- **20% ≤ Disorder < 50%** → Medium (O(n√n))
- **Disorder ≥ 50%** → Complex (O(n log n))

**Justification**: No single algorithm is optimal for all inputs. By measuring the disorder level beforehand, we can choose the strategy that will likely produce the fewest operations for that specific input. This hybrid approach maximizes performance across the entire spectrum of possible inputs.

**Disorder Calculation**: The disorder is computed as the ratio of inversions (pairs where i < j but a[i] > a[j]) to the total number of possible pairs (n*(n-1)/2). A perfectly sorted array has 0% disorder; a reverse-sorted array has 100% disorder.

