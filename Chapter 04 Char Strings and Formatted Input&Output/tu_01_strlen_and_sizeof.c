/* In this .c file, we will cover:
                        preprocessor, constant, string, strlen() and sizeof. */

#include <stdio.h>
// so as to use printf() and scanf()
#include <string.h>
// so as to use strlen() in this file, which is obsolete in post-ANSI C compiler
#define MYNAME "Eiger"



int main(void)
{
    int length, size;
    char name[40];
    // a character string is a character array, i.e. an array of characters
    // defined in the same way as integer array
    // we use "" to indicate it's a string
    // '' is for (a single) character
    printf("Please enter your name: ");
    scanf("%s",name);
    // since name is also a char pointer,
    // its content is the location of the first char in string name
    // we can therefore use name instead of &name in scanf()
/* array */
    // an array is an ordered sequence of data elements of one type.
/* null character*/
    // What stored in memory is actually "entered_name\0"
    // the "\0" is a null character that mark the end of a string
    // only a string has \0, i.e. any string occupies at least 1 memory cell
    // that is to say, char name[40] can store 39 characters at most.
    // e.g.    def               memory
    //      char a = 'x'          x
    //      char a[1] = "x"       x /0
/* more on scanf()*/
    // scanf("%s",&myString) only read one string, i.e. whatever before the first whitespace (newline, tab, space)
    // to read more than one string, use other I/O fn.s like fgets() (see later chapter)
    length = strlen(name);
    size = sizeof name;
    //
    printf("Hi, %s. I'm %s. Your name consists of %d letters\n"
           ,name,MYNAME,length);
    // 1. Here, we call the predefined string MYNAME in printf()
    // 2. one can break down a printf() like this
    //      but you can only break it between arguments
    printf("Your name takes %zd bytes to store and mine %zd bytes",size, sizeof MYNAME);
    // "zd" is for signed integer
    /* !!! unsigned/signed values need review !!! */
    return 0;
}
