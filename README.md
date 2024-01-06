![Push Swap](https://imgur.com/FnPH2OT)

# Push Swap Project :twisted_rightwards_arrows: :computer:

## About the Project :page_facing_up:

Push Swap is an intriguing journey into the realm of sorting algorithms and stack operations. Designed to challenge abilities in manipulating data structures and using classic sorting algorithms to solve practical problems, Push Swap stands out in the algorithmic landscape.

## Features :sparkles:

- **Efficient Sorting**: Harnesses advanced sorting algorithms for effective data organization.
- **Stack Operations Mastery**: Complex operations on stacks to manipulate data.
- **Optimization for Performance**: Code optimized for peak performance and efficiency.

## How it Works :gear:

Push Swap sorts integers on a stack with a limited set of instructions, using the least possible moves. It comprises two stacks named `a` and `b`. Initially, `a` contains a random number of positive or negative integers without duplicates, and `b` is empty. The goal is to sort the numbers in `a` using a limited set of instructions.

## Instruction Set

For the following instructions, if the instruction is not possible, the part of it that can't be executed won't be executed.

| Code | Instruction                         | Action                                             |
| ---- | ----------------------------------- | -------------------------------------------------- |
| sa   | swap a                              | swaps the 2 top elements of stack a                |
| sb   | swap b                              | swaps the 2 top elements of stack b                |
| ss   | swap a + swap b                     | both sa and sb                                     |
| pa   | push a                              | moves the top element of stack b to top of stack a |
| pb   | push b                              | moves the top element of stack a to top of stack b |
| ra   | rotate a                            | shifts all elements of stack a from bottom to top  |
| rb   | rotate b                            | shifts all elements of stack b from bottom to top  |
| rr   | rotate a + rotate b                 | both ra and rb                                     |
| rra  | reverse rotate a                    | shifts all elements of stack a from top to bottom  |
| rrb  | reverse rotate b                    | shifts all elements of stack b from top to bottom  |
| rrr  | reverse rotate a + reverse rotate b | both rra and rrb                                   |

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
   git clone https://github.com/rogalio/PushSwap
   ```
2. **Compile the Project**:
   This will compile the `push_swap` and optionally the `checker` programs.

## Usage :bookmark_tabs:

- **Push Swap**:
  ```bash
  ./push_swap 3 2 1 7 6
  ```
- **Checker (Bonus)**:
  ```bash
  ARGS ="3 2 1 7 6"; ./push_swap $ARGS | ./checker $ARGS
  ```

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
