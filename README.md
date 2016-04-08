# Brainfuck Project
This project is aimed at exploring the esoteric progamming language of Brainfuck (excuse the vulgarity). The project consists of several components.
##Brainfuck Interpreter
The main component of this project is the Brainfuck interpreter contained within. The interpreter is written in C, saved as **brainfuck_interpreter.c**.
Before running any brainfuck code, this interpreter must be compiled with gcc. All code tested so far on this interpreter has executed correctly. It
should continue to be effective. If you find any error in the brainfuck (bf) code execution and you are sure it is not user error, please let me know.
##BF Code
There is sample bf code within the directory bf_code. Note that by convention all bf code ends in the suffix ".bf". Feel free to peruse and add
to this code.
##Executing BF Code
As stated earlier, before executing any code, the interpreter must be compiled with gcc. To execute a bf code file, run the interpreter, passing
in the file path as a parameter. Include any input that the bf code requires after the file path. Note: if the input includes spaces, make sure that you encase the input in quotations. \n
Here is an example of bf code execution: \n
**./brainfuck_interpreter bf_code/hiAll.bf "Everyone I know and love"**
\n

If there is no input, simply omit the last command-line argument.

