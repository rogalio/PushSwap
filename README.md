# Push Swap Project :twisted_rightwards_arrows: :computer:

## About the Project :page_facing_up:

Push Swap is an intriguing journey into the realm of sorting algorithms and stack operations. Designed to challenge abilities in manipulating data structures and using classic sorting algorithms to solve practical problems, Push Swap stands out in the algorithmic landscape.

## Features :sparkles:

- **Efficient Sorting**: Harnesses advanced sorting algorithms for effective data organization.
- **Stack Operations Mastery**: Complex operations on stacks to manipulate data.
- **Optimization for Performance**: Code optimized for peak performance and efficiency.

## How it Works :gear:

Push Swap sorts integers on a stack with a limited set of instructions, using the least possible moves. It comprises two stacks named `a` and `b`. Initially, `a` contains a random number of positive or negative integers without duplicates, and `b` is empty. The goal is to sort the numbers in `a` using a limited set of instructions.

## Sorting Algorithm Explained :mag:

The core of Push Swap is its sorting algorithm, which employs a "cost-based" approach. The algorithm calculates the cost (in terms of moves) to bring each element to its correct position and executes the most efficient set of operations to achieve the sorted stack.

### Algorithm Steps:

1. **Indexing**: Assigns each element a position based on its value relative to others.
2. **Chunking for Large Sets**: For larger datasets, the stack is divided into chunks, and each chunk is sorted individually.
3. **Rotations and Swaps**: Uses stack operations (`ra`, `rb`, `rr`, `sa`, `sb`, `ss`) to position elements correctly.

## Bonus Part - Checker :heavy_check_mark:

The bonus part includes a `checker` program that takes integer arguments and a series of operations, then checks if these operations would sort the stack.

### Checker Working:

- **Input Operations**: Reads operations and applies them to the stack.
- **Validation**: After all operations are applied, it checks if the stack is sorted.
- **Output**: Prints `OK` if the operations sort the stack, otherwise `KO`.

## Installation and Compilation :wrench:

1. **Clone the Repository**:
   ```bash
   git clone [Your Repository URL]
   ```
2. **Compile the Project**:
   This will compile the `push_swap` and optionally the `checker` programs.

## Usage :bookmark_tabs:

- **Push Swap**:
  ```bash
  ./push_swap [list of numbers]
  ```
- **Checker (Bonus)**:
  ARGS ="[list of numbers]"; ./push_swap $ARGS | ./checker $ARGS

## How the Algorithm Works :bulb:

- The algorithm calculates the most efficient sequence of actions to sort the stack.
- It assigns an index to each element and uses various operations to sort the stack.
- For larger stacks, it divides the stack into manageable chunks and sorts each chunk.

## Contribution :handshake:

Contributions to the Push Swap project are always welcome. If you have suggestions or improvements, feel free to fork the repository and submit a pull request.

## License :balance_scale:

This project is licensed under [Your License Type]. For more details, see the LICENSE file in the repository.

---

:star: Don't forget to star this project if you find it useful!
