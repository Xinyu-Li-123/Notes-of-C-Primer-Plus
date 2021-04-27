/* This .c file covers concepts about character I/O and input validation */

#include <stdio.h>

void print_char(char ch,int row, int col)
{
    int i,j;
    for (i = 1; i <= row; i++){
        for (j = 1; j <= col; j++){
            printf("%c",ch);
        }
        printf("\n");
    }

}

int main(void)
{
/* Part 1. Buffers

    Buffer is an area of temporary storage.
    When getting input, if stored in buffer first, then the input is buffered
                        if directly send to the waiting program, then the input is unbuffered
    Both kinds of input have their own usage.

    Type of input:
        Buffered input:
            less time-consuming
            allow users to correct their mistype

        Unbuffered input:
            allow immediate reaction, suitable in some cases like pressing keys in a games

    Type of Buffered I/O:
        Full-buffered I/O:
            Won't flush until the buffer is full.
            (flush: send the contents in buffers to the destination)
            (buffer size: 512 Bytes or 4096 Bytes)
            Usually occurs with file input

        Line-buffered I/O:
            Won't flush until a newline character '\n' ([enter])
            Usually appear in keyboard input
*/
    char ch;
    printf("Echo the input with # to stop\n");
    while ((ch = getchar()) != '#'){
        putchar(ch);    // This print out whatever you enter. This is called echoing the input.
    }



/* Part 2. Terminating Keyboard Input

What should I do if there is a # in my sentence?

1/ How C handles files
1// File: an area of memory in which information is stored
        Normally kept in permanent memory.
        Programs can open, read, write, close a file.

    There is low-level I/O (library functions ?) that are specific to different OS.
    There is also standard I/O (library functions ?) that provides users with a uniform interface,
        leaving the difference between OSs to the implementation of C.

 |  Conceptually, C deal with streams instead of files

2// Stream: an idealized flow of data to which the actual input & output are matched
            Various kinds of input with differing properties are represented by streams with more uniform properties.
            The process of opening a file then becomes one of associating a stream with the file,
            reading and writing the file take place via the stream.

    C treats I/O devices the same as it treats files in storage.
    Keyboard and display device are treated as files opened automatically.
    Keyboard input is repr by a stream called "stdin".
    Display output is repr by a stream called "stdout".

    printf(), scanf(), getchar(), putchar() deal with these two streams.

    One implication is that one can apply techniques for files to keyboard I/O
        e.g. When reading a file, a program need a way to detect the end of that file.
             C has a built-in, end-of-file detector.
                Thus we can apply this detector to keyboard input.
*/





/* Part 3. The End of File

    How does OS show the end of a file?
        method 1: End-of-file Character
            usually ctrl+z

        method 2: Keep Track of the Size of the File
            For a 3kb file, if the program have read 3kb, then it must reach the end.
            This allows the file to hold all characters.

    getchar() will return a special value called EOF when they reach the end of a file (same with scanf()).
    EOF is defined in the stdio.h as follow:
        define EOF (-1)
    getchar() return the ASCII code of the read char.
    We choose -1(or any other appropriate value) for EOF so that it doesn't match any character's ASCII code.
    EOF is a built-in constant.
    But you shouldn't assume the value of EOF in your program.

    Thus, we can modify our input-echoing program with EOF as follow:
*/

    // echo_eof.c
    printf("Do this again with EOF.\n");
    // EOF on my computer is Ctrl+D at the beginning of a new line.
    // It will only end the input, instead of the whole program.
    while ((ch = getchar()) != EOF){
    // Note that EOF is int, but ch is char. Luckily, getchar() returns int,
    // so the comparison still works thanks to promotion.
    // Don't worry, this won't jinx putchar().
        putchar(ch);
    }

    /* The possibility for echo_eof.c
        With this short program, we can feed in an input file to make a copy (reading will stop at EOF),
        and write the copy into an output file (writing will stop at EOF).
        Thus, this small program can
            look at the contents of files
            create new files
            make copies of files

        All we need now is to know how to control the flow of input and output.
    */


/* Part 4. Redirection and Files
    I/O involves functions,      data   and    device
          e.g.    getchar()   characters      keyboard

    To get a program to work with file, one could
        1/ explicitly use special functions (see Chapter 13)

        2/ redirection
            redirect keyboard I/O to and from files
            e.g. reassign the stream stdin to a file
                    getchar() will continue to get its data from the stdin stream, not caring where the stream is assigned

            Redirecting input enables your program to use a file instead of the keyboard for input
            Redirecting output enables your program to use a file instead of the screen for output

            redirection operator: < >
            1// <: input from a file (read a file)
                  In cmd, enter
                    echo_eof.exe < poem.txt
                  the "<" associate poem.txt file to stdin stream
                        echo_eof.exe(complied echo_eof.c) read data from input stream, which is associated with poem.txt
                  Here, echo_eof read input from text.txt and write output on the screen
                        (this make text.txt file a input device)

            2// >: output to a file (write a file)
                  In cmd, enter
                    echo_eof.exe > text.txt
                  the ">" associate word.txt file to stdout stream
                        (if word.txt DNE, then create a new file)
                  Here, echo_eof read input from keyboard and write output into word.txt file

            3// < >: input from a file, output to another file
                  You can also do this:
                     echo_eof < poem.txt > word.txt
                  Here, echo_eof read input from poem.txt and write output into word.txt

                        rmk. Don't use echo_eof < poem.txt > poem.txt
                                b/c > will truncate poem.txt to zero length before it ever be used as input

            Rules for redirection operators (< and >):
                i) A redirection operator can only connect an executable program with a data file
                        it can't connect two data files or two programs
               ii) When using redirection operators,
                        input can't be taken from more than one file,
                        output can't be directed to more than one file.

*/



/* Part 5. Tips on creating friendlier user interface */

    /* 1. Anticipate all kinds of possible input*/

    // The following program can guess the number you think.
    char response;
    int guess = 0;
    printf("\n\n-------------------------------\n     Number Guessing Game\n");
    printf("Please think of a number (0~100). I'll try to guess it out. If I were right, enter y. Wrong, enter n\n");
    printf("Is it %d?\n",guess);

    while ((response = getchar())!= 'y'){
        if (response == 'n'){
            printf("Well, let me try again. Is it %d?\n", ++guess);
        }
        else{
            printf("I can only recognize y or n. Please enter your response again.\n");
        }
        while (getchar() != '\n'){
            continue;               // read the first char only and skip the rest of the input line
        }
        // rmk, here, we leave the last '\n' undeleted, so that in while test, it will be skipped
    }
    printf("I knew I could do it!\n");
    fflush(stdin);

    /* 2. Mixing numeric and character input

    When mixing numeric and character input, one will use both scanf() and getchar() to read input.
    However, scanf() and getchar() don't mix well.
        scanf(), when reading numbers, skips over spaces, tabs, and newlines
        getchar() reads every character, including spaces, tabs, and newlines

    */

    int row, col;

    printf("\nEnter char (char), row (int), col (int) to print a row*col square of char. (enter a newline to quit)\n");
    while ((ch = getchar()) != '\n'){
        if (scanf("%d %d",&row, &col) != 2){
            printf("Please enter the input correctly\n");
        }
        else
            print_char(ch,row,col);
        while (getchar() != '\n')
            continue;
        // This while loop is meant to clear all the rest char in stdin
        //      b/c scanf stop at the second number, the rest input are still left in stdin.
        printf("\nEnter the next char, row and col.\n");
    }


/* Part 6. Input Validation */


    return 0;
}
