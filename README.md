# Push_swap

*This project was developed as part of the 42 curriculum by **akahrama** and **bakumcu**.*

---

## Description

Push_swap is an algorithm project that sorts a list of integers in ascending order by using only two stacks (`stack_a` and `stack_b`) and a limited set of operations. The program does not print the sorted list directly; instead, it outputs the sequence of operations (`sa`, `pb`, `ra`, `rra`, etc.) that can be executed by a checker.

In this implementation, all values are first normalized into indexes in the `0..n-1` range. This allows the algorithms to work with each element's sorted position instead of dealing directly with negative, positive, or very large integer values. Small inputs are handled by dedicated routines, while larger inputs are sorted with selection-based, chunk-based, or LIS + cost-based strategies.

---

## Instructions

### Compilation

The project includes a standard `Makefile` compiled with the `-Wall -Wextra -Werror` flags. To build:

```bash
make
```

Cleaning commands:

```bash
make clean
make fclean
make re
```

### Execution

The program receives integers as arguments and writes the required sorting operations to `stdout`.

```bash
./push_swap 4 67 3 87 23
```

Passing the numbers as a single quoted argument is also supported:

```bash
./push_swap "4 67 3 87 23"
```

For invalid input, duplicate values, or numbers outside the `int` range, the program writes `Error` to `stderr`.

### Available Flags

| Flag | Description |
|------|----------|
| `--simple` | Forces the simple strategy that repeatedly moves the minimum element to `stack_b` |
| `--medium` | Forces the medium strategy based on indexed chunks |
| `--complex` | Forces the advanced strategy using LIS and cost calculation |
| `--adaptive` | Selects a strategy according to the disorder metric |
| `--bench` | Prints the selected strategy, disorder ratio, and operation counts to `stderr` |

Example:

```bash
./push_swap --bench --complex 8 2 5 1 9 3
```

---

## Algorithms and Complexity Justification

### 1. Simple Algorithm: Selection-Based Sort — O(n²)

**Strategy:** The minimum indexed element in `stack_a` is found, moved to the top using the shortest rotation direction, and pushed to `stack_b` with `pb`. This continues until only three elements remain in `stack_a`. The last three elements are sorted with the dedicated `sort_three` routine, then the elements in `stack_b` are pushed back with `pa`.

This method is simple and effective for small or nearly sorted inputs. However, because it searches for the minimum and rotates the stack on every pass, the operation count grows quickly on larger lists.

### 2. Medium Algorithm: Chunk-Based Sort — O(n√n)

**Strategy:** The normalized indexes are divided into chunks of approximately `sqrt(n) * 1.4`. The program first pushes elements belonging to the current chunk range into `stack_b`. Elements from the lower half of the chunk are rotated with `rb`, creating a more useful distribution inside `stack_b`.

After all elements are moved to `stack_b`, the maximum indexed element is repeatedly brought to the top using the shortest rotation path and pushed back to `stack_a` with `pa`. Since the elements are restored from larger to smaller, `stack_a` ends up sorted in ascending order.

### 3. Complex Algorithm: LIS + Cost-Based Insertion — O(n log n) LIS, O(n²) placement

**Strategy:** The program first finds the Longest Increasing Subsequence (LIS) already present in `stack_a`. These elements are kept in `stack_a`, while every non-LIS element is pushed to `stack_b`.

Then, for each element in `stack_b`, the correct target position in `stack_a` is calculated. The program compares the required `ra/rra` and `rb/rrb` costs for inserting that element into the right place. Rotations in the same direction are combined with `rr` or `rrr` to reduce the total number of operations. On each iteration, the cheapest element is selected and pushed back to `stack_a` with `pa`.

At the end, the minimum indexed element is moved to the top using the shortest direction. This turns the cyclically sorted stack into a fully ascending stack.

### 4. Custom Adaptive Algorithm

At startup, the program calculates a **Disorder Metric** for the input. This metric is based on the ratio between inverted pairs and the total number of possible pairs in the list.

| Disorder Value | Selected Algorithm |
|--------------------|-------------------|
| `< 100` | Simple strategy |
| `100 <= value < 300` | Medium chunk strategy |
| `>= 300` | Complex LIS + cost strategy |

This value is stored on a 1000-point scale inside the code. For example, `300` represents roughly `30%` disorder.

---

## Resources & AI Usage

### Resources

- 42 Push_swap subject
- Linked list stack implementation notes
- Longest Increasing Subsequence algorithm references
- Push_swap operation optimization examples

### AI Usage

AI assistance was used to turn the existing code structure into a clear README document. The explanations are based on the actual files and algorithm flow of this project.

AI was especially helpful for:

- **Documentation:** Simplifying the code flow into a readable README format.
- **Algorithm Explanation:** Summarizing the selection, chunk, and LIS + cost strategies clearly.
- **Consistency Check:** Keeping the README aligned with the current implementation.

---

## Group Contributions

| Member | Contributions |
|-----|----------|
| **akahrama** | Parsing, input validation, stack operations, indexing, benchmark mode, simple/medium/complex/adaptive sorting strategies, and memory management |
