#include <stdio.h>


void main(void)
{
/*
    Extra: Recap on how a .c file is compiled


    1// Workflow of compilation

            source code file (main.c)
                    |
                    |
                    V
              Pre-Processor
                    |
                    |
                    V
                Compiler
                    |_________
                              |
                              V
                         Assembly code
                              |
                     _________|
                    |
                    V
                Assembler
                    |
                     ---------->|
                                | Object file (main.o)
    Libraries -----|  |---------|
                   |  |
                   V  V
                  Linker
                    |
                    |
                    V
            Executable file (main.exe)

    2// Explanation

    The preprocessor
        -  gets rid of comments in the source file (main.h)
        -  includes the code of the header files (.h)
                which contains C function declarations and macro definition
        -  replace macros by their values
                (macros are fragments of code which have been given a name)

        After preprocessing, we get a main.i file
        To stop compiling at this step, we can use -E (gcc -E main.c)


    The compiler
        - take the preprocessed file and generate IR code
                (IR: Intermediate Representation)
        - it might produce assembly code

        After compiling, we get a main.s file
        To stop at this step, use -S


    The assembler
        - take the IR code and transform it into object code

        After compiling, we get a main.o file
        To stop at this step, use -C


    The linker
        The linker creates the final executable file in binary
        It can
        -  link all source file together
                (i.e. all the object files in the project)
           e.g.
           To compile main.c with another file called secondary.c
                and make them into a single program,
                we can link their object files together.

        -  link function calls with their definitions
           The linker will look for the function definitions in
           the static libraries and the dynamic libraries

           static libraries : the result of the linker making copy
                                    of all used library functions
                                    to the executable file
           dynamic libraries: don¡¯t require the code to be copied,
                                    it is done by just placing the name
                                    of the library in the binary file

        rmk. This is the reason why Code::Blocks always generates a .o file after compilation,
                so that you can link it with other .o files later

    3// More on compiling .c file with cmd

    Edit name
        gcc -o NameOfExe.exe FileToBeCompiled.c
        In this way, gcc will compile FileToBeCompiled.c
            and generate NameOfExe.exe.

    As an example, see print_str.c

*/



}
