# Monty Interpreter

This is a simple interpreter for Monty bytecode written in C. The Monty language is a stack-based language where instructions are executed based on a stack data structure. This interpreter reads Monty bytecode files and executes the corresponding instructions.

## Features

- Executes various Monty bytecode instructions, including push and pall.
- Handles error cases and provides meaningful error messages.
- Supports reading Monty bytecode files and executing the instructions.

## Requirements

- GCC compiler (or any C compiler) to build the code.
- Linux or Unix-based system to run the interpreter.

## Usage

1. Clone the repository:
$ git clone https://github.com/JeanFab0307/monty.git
$ cd monty-interpreter


2. Compile the code:
$ gcc -o monty *.c


3. Run the interpreter with a Monty bytecode file:
$ ./monty monty.m


## Monty Bytecode Files

Monty bytecode files are plain text files containing Monty instructions. Each instruction is written on a separate line. Supported instructions include:

- `push <int>`: Pushes an integer onto the stack.
- `pall`: Prints all the values on the stack.

For example, a sample Monty bytecode file (`monty.m`) may look like:

push 1
push 2
push 3
pall


Running the interpreter with this file will push three integers onto the stack and then print them using the `pall` instruction.

## Contributing

Contributions are welcome! If you find any bugs or want to add new features, please feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
