/* This .c file covers the basic knowledge of file in C */

/*
    Files are essential to computer. They are used to store a variety of things in computer
        such as programs, documents, data, etc. In this chapter, you will lean how write programs
        that create files
             write into files
             read from files
*/

#include <stdio.h>
#include <stdlib.h>


/*
1/ Communication with Files
    C offers smarter way to handle files than file redirection as in echo_eof

    1// What is a File?
        A file is a named section of memory on a disk or solid-state device.

        C views a file as a continuous sequence of bytes, each of which can be read individually,
            in accordance to Unix, the environment where C grew up
            There are 2 ways to view files in C: text view and binary view

    2// The Text Mode and the Binary Mode
                                                         | content |
        Let's first distinguish between text and binary -| formats |- for files
                                                         | modes   |

        All files content are in binary form (0 and 1).

        If a file primarily uses the binary codes for characters to repr text (e.g. ASCII),
            then it's a text file and it has text content.
        If the binary values in a file repr machine-language, numeric data, or image & music encoding,
            then it has binary content


    3// Levels of I/O
        There are 2 levels of I/O:
            Low-level I/O that differs for diff OSs.
            High-level I/O, the portable, standard I/O model.

    4// Standard Files
        C opens 3 files automatically:
            standard input       : input devices like keyboard, read by getchar() and scanf()
            standard output      : output devices like screen, written by printf(), ...
            standard error output: an individual place to send error messages.
                                        w/o which error will also be written to output_file
                                        when running echo_eof.exe, and you can't see them
                                        from the screen immediately.

2/ Standard I/O
    The standard I/O has two more pros than low-level I/O besides portability:
    -   more functions that simplify handling diff I/O problems
            (e.g. printf() can convert diff data types into string output)
    -   buffered I/O, instead of one-byte-at-a-time


*/
unsigned long count(char *argv)
{
    char ch;     // place to hold each char as read
    FILE *fp;   // fp is a pointer-to-FILE, a pointer of a FILE variable
/*
    1// FILE and pointer-to-FILE:
    fp is a pointer-to-FILE. FILE is a derived type defined in stdio.h. The pointer fp
        doesn't point to the actual file. Instead, it points to a data object (C structure)
        containing info about the file, including the buffer used forthe file's I/O.
*/

    unsigned long count = 0;
    if((fp = fopen(argv, "r")) == NULL)
    {
        printf("Can't open %s\n", argv);
        exit(EXIT_FAILURE);     // 0 if exit normally, !0 if not
    }
/*
    2// fopen():
    The program uses fopen() to open a file. This function is declared in stdio.h. It's
        1st arg is the name of the file to be opened (the address of a string containing
        the name of the file). The 2nd arg is a string identifying the mode in which the
        file is to be opened. The C lib provides several modes:
        Mode String     Meaning
            "r"         Open a text file for reading

            "w"         Open a text file for writing, truncating an existing file to zero length,
                            or creating the file if it doesn't exist

            "a"         Open a text file for writing, appending to the end of an existing file,
                            or creating the file if it doesn't exist

            "_+"        _ is for r, w, or a; + means open the file for update (i.e. reading and witing)

            "_b"        _ is for r, w, a, r+, w+, a+; b means open the file in binary mode

            "_x"        _ is for w, wb, w+, wb+; x means 2 features:
                            -   the file-opening will fail if the file already exists.
                                    This can protect an existing file from being truncated to zero by "w".
                            -   the file, if opened, is in exclusive mode. That is, other programs and threads
                                    can't access the file untile the current process closes the file.

    If fails to open the file, fopen() will return a NULL pointer.
    If successfully opens the file, fopen() will return a pointer-to-FILE with which other I/O functions
        can then use to specify the file.


*/

/*
    3// putc() and getc()
    getc() and putc() is similar to getchar() and putchar()
        except you need to specify which file to get / put
        with a file pointer like stdin, stdout, stderr
        e.g. getc(fp);   putc(ch, fpout);
*/
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }

    count++;

    printf("File %s has %lu characters\n", argv, count);
    fclose(fp);
/*
    4// fclose():
    fclose(fp) closes the file pointed by fp and flush buffers.
    If it fails to close the file, it will return 0.
    Failure to close a file can be a result of a full disk

*/

    return count;
}

void print_file(char *floc)
{
/*
    5// Another example
*/
    char ch;
    FILE *fp;
    if((fp = fopen(floc, "r")) == NULL){
        printf("Can't open the file\n");
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF){
        putc(ch, stdout);
    }
    fclose(fp);
}

/*
2/ A Simple-Minded File-Condensing Program

*/

void reducto(char *infloc, char *outfloc)
// reducto(input_file_location, output_file_location)
{
    char ch;
    unsigned long count = 0;
    FILE * infp;
    FILE * outfp;


    if(infloc == ""){
        infp = stdin;
        printf("Please enter a line to compress: ");
    }
    else
        infp = fopen(infloc, "r");

    if(outfloc == "")
        outfp = stdout;
    else
        outfp = fopen(outfloc, "w");

    if(infp == NULL || outfp == NULL){
        fprintf(stderr, "Fail to open I/O file");
        exit(EXIT_FAILURE);
    }


    while((ch = getc(infp)) != '\n'){
        if(count++ % 3 == 0)
            putc(ch, outfp);
    }

    if(fclose(infp) != 0 || fclose(outfp) != 0)
        fprintf(stderr, "Fail to close files\n");
}

/*
    1// File I/O functions:
    getc():
        getc(stdin);

    putc():
        putc('a', stdout);

    The "f" prefix: f + I/O function -> file I/O function. A file I/O function
        is similar to the I/O function except that you need an extra FILE pointer
        to tell the function which file to work.

    fprintf():
        fprintf(stdout, "Some words");

    fscanf():
        char words[30];
        fscanf(stdin, "%29s", words);

    fgets():
        char buf[100];
        fgets(buf, 99, infp);   // get 99-char string from infp and store them in buf

    fputs():
        fputs(buf, outfp);      // put buf into outfp
*/

void echo_twice(char * inloc, char * outloc)
{
    FILE * inf;
    FILE * outf;
    char inf_content[1000];
    if(inloc == "")
        inf = stdin;
    else
        inf = fopen(inloc, "r");
    if(outloc == "")
        outf = stdout;
    else
        outf = fopen(outloc, "w");
    if(inf == NULL || outf == NULL)
        fprintf(stderr, "Fail to open files.\n");

    while(fgets(inf_content, 99, inf)){
        fputs(inf_content, outf);
    }
    rewind(inf);
    putc('\n', outf);
    while(fgets(inf_content, 99, inf)){
        fputs(inf_content, outf);
    }


    if(fclose(inf) != 0 || fclose(outf) != 0)
        fprintf(stderr, "Fail to close files.\n");
}



/*
3/ Random Access: fseek() and ftell():
    fseek() enables you to treat a file like an array and move directly
        to any particular byte in a file opened by fopen().

    fseek():
        fseek(fp, xL, SEEK_MODE)
        -   fp is the pointer-to-file, it indicates which file to seek
        -   xL is a long that indicates the search direction (step of each search, e.g. 2, -3, 0)
        -   SEEK_MODE: mode of seek, there are SEEK_SET: from the beginning
                                               SEEK_CUR: from current position
                                               SEEK_END: from the end of the file
            e.g.  0L, SEEK_SET: go to the beginning of the file
                  10L, SEEK_CUR: advanced 2 bytes from current position
                  -5L, SEEK_END: back up 5 bytes from the end of the file

        fseek() moves the pointer-to-file fp to the location indicated by the 3 args.
        fseek() returns 0 if search correctly, -1 if error (say the searching exceed the end of the file)

    ftell():
        ftell() is type long. It returns the current file location, which is indicated by the number
            of bytes from the beginning, with the first byte being 0 byte.

    !! (why binary mode) fseek() and ftell() applies to binary mode, but not necessarily to text mode. !!

    To better understand these two funcs, let's build a function that print a file in reverse order.
*/

void reverse(char * infloc, char * outfloc)
{
    FILE * inf;
    FILE * outf;
    char ch;
    inf = (infloc == "") ? stdin : fopen(infloc, "rb");
    // !! to use fseek() and ftell(), the file must be opened in BINARY mode !!
    outf = (outfloc == "") ? stdout : fopen(outfloc, "w");
    if(inf == NULL || outf == NULL)
        fprintf(stderr, "Fail to open files.\n");

    fseek(inf, 0L, SEEK_END);
    long last = ftell(inf);
    for(long count = 1L; count <= last; count++){   // start counting from 1 to skip the last char '\0'
        fseek(inf, -count, SEEK_END);
        ch = getc(inf);
        putc(ch, outf);
    }

    if(fclose(inf) != 0 || fclose(outf) != 0)
        fprintf(stderr, "Fail to close files.\n");
}

/*
4/ fgetpos() and fsetpos()
    However, fseek() and ftell() are limited b/c they repr file sizes with a long value,
        which has a limited length. ANSI C offers two alternative funcs: fgetpos() and fsetpos()

    fgetpos() and fsetpos() substitute long with fpos_t, a new type, to repr file pointer location.
        a variable of fpos_t type can specify a location within a file (it may be a structure type?)
    It't not a fundamental type.

    1// prototype
    int fgetpos(FILE * restrict streem, fpos_t * restrict pos);

    int fsetpos(FILE * stream, const fpos_t * pos);

    Both funcs return 0 if succeeded, return non 0 if failed.

    When fsetpos() is called, the fpos_t value should have been obtained by a previous fgetpos().


5/ The model (work-flow) of standard I/O:
        Call fopen() to open a file
                   set up a buffer
                   set up a data structure containing
                        data 'bout the file and the buffer:
                        -   a file position specifying the
                                current position of the stream
                        -   indicators for errors and EOF
                        -   a pointer to the beginning of the buffer
                        -   a file identifier
                        -   a count for the number of bytes copied into the buffer
                   return a pointer of this structure
        (fopen() is said to "open a text / binary stream")

                |
                |
                v

        Call a file input / output function declared in stdio.h (e.g. fscanf())
        -   A chunk of data the size of the buffer will be copied to the buffer.
        -   Once all chars in the buffer are processed (read, write, append...), next chunk of data of the same size will be copied
        -   This shall terminate when reaching EOF.

6/ Other interesting standard I/O functions
1// ungetc()
    int ungetc(int c, FILE *fp);
    To make c read the char one step before the current file position
    e.g.
        // input queue: Mary
        char ch_ = getchar();  ==> ch = 'M', fp move to 'a'
        ungetc(ch, stdin);     ==> fp move back to 'M'
        char ch_2 = getchar(); ==> ch_2 = 'M'


*/


int main()
{
    char * infloc = "D:\\Eiger\\Coding\\C\\elementary_tutorial\\C Primer Plus\\poem.txt";
    char * outfloc = "D:\\Eiger\\Coding\\C\\elementary_tutorial\\C Primer Plus\\word.txt";

    //count(infloc);
    //print_file(outfloc);
    //reducto("", outfloc);       // "" as in stdin or stdout
    //echo_twice(infloc, "");
    reverse(infloc, "");

    return 0;
}
