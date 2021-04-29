#include <stdio.h>
#define STRLEN 10

int s_gets_myver(char *input_str, int n)
// This is my version of s_gets(), it returns an int flag indicating if the input is empty.
{
    int i = 0;
    while((input_str[i] = getchar()) != '\n' && i < n)
        i++;
    if (i > n){
        input_str[i+1] = '\0';
        while(getchar() != '\n')
            continue;
    }
    else
        input_str[i] = '\0';
    return (  (input_str[0] != '\0') ? 1 : 0 );
}


char *s_gets(char *input_str, int n)
// This is the s_gets() in C Primer Plus (with some modification).
//      It makes use of the NULL pointer to indicate if the input is empty
{
    int i = 0;
    char *ret_val;
    ret_val = fgets(input_str,n + 1,stdin);
    if (ret_val){   // i.e. if (ret_val != null): fgets return null pointer if it reads EOF only.
        while (input_str[i] != '\n' && input_str[i] != '\0')
            i++;
        if (input_str[i] == '\n')
            input_str[i] = '\0';        // make sure the input_str ends with '\0'
        else{
            while (getchar() != '\n')   // clear the stdin
                continue;
        }
    }
    return ret_val;
}

void scanf_str(void)
{
    char myStr_1[10];
    char myStr_2[10];
    int count;
    printf("Please enter two words: ");
    while((count = scanf("%2s %3s", myStr_1, myStr_2)) == 2){
        printf("I've read %d words. They are: \"%s\" and \"%s\"\n", count,
               myStr_1, myStr_2);
        fflush(stdin);
        printf("Please enter two words: ");
    }
}








void main(void)
{
/* Part 2. String Input
    0// Set aside space for string input
            To read string input into a program, one must set aside space for string beforehand
            This kind of code will cause problem:

        char *input_str;
        scanf("s",input_str);

            Since the pointer input_str is uninitialized, it can point everywhere.
            This may make scanf overwrite other data in the memory.

            instead, we should use

        char input_str[40];

    1// the unsafe gets()
            To get string input, we can use get(arr)
            get(arr) reads one line, stores it in arr, and replaces the last '\n' with '\0' to turn it into a string    */


    char input_str[STRLEN];
    printf("Enter some characters: ");
    gets(input_str);
    puts(input_str);


    /*  However gets() is dangerous because
            -it doesn't check if input line actually fits into the array (size-wise)
            -if the input string is too long, you will get a buffer overflow


    2// Alternative to gets(): fgets()

        fgets(input_str, n, filename)
            - Used for file input.
            - Read up to the n - 1 char or the newline char, whichever comes first
            - Will store the newline char, unlike gets()
            - Indicate the file to read in the 3rd arg
                    To read from keyboard, filename = stdin

        fputs(input_str, filename)
            - similar to puts(), but no automatically appended newline at the end
            - 2nd arg indicates which file to write to
                    To write on screen, filename = stdout
    */

    fflush(stdin);

    printf("Enter 5 characters: ");
    char *a = fgets(input_str, 7, stdin);         // notice how the newline char is saved and used
    fputs(input_str, stdout);
    printf("%c",*(a+2));
    puts("Done");

    /*
        Why fgets( ,7, ) ?
            We want to input a 5-letter word (e.g. Hello) with a newline
                Thus, strlen = 5 (5 letters) + 1 ('\n') + 1 ('\0', indicate str) = 7
            If we don't want the '\n', we can change 7 into 6

        What does fgets() return ?
            - If all goes well,    return a pointer to the input_str
                (point to the same address as pointer input_str)
            - If meet end-of-file (EOF), return a null pointer
                This null pointer points to no valid data
                used to indicate this special case
                repr. by NULL
    */

    fflush(stdin);

    puts("Enter some strings(empty line to quit)");
    while ((fgets(input_str, 10, stdin)) != NULL && input_str[0] != '\n'){
        fputs(input_str, stdout);
    }
    puts("Done");

    /*  rmk
            The strlen is 10. But even if input strlen > 10,
                there seems to be no problem
            b/c of buffered I/O

            take "Hello world! I'm here."[enter] as an example,
            what is printed ?
                By prop of fgets() and fputs(), the input string is divided into
                    Hello wor\0
                    ld! I'm h\0
                    ere.\n\0


        Pros and cons of fgets()
            Since fgets() save the '\n',
                pros: use this prop to tell if the whole line is read
                cons: when you don't wanna store the '\n'
    */

    /* Illustrative program:
            - read first 10 chars of a line and print them out
            - discard the leftover chars
            - If reach EOF || read an empty line, quit      */

    while ((fgets(input_str, STRLEN + 1, stdin )) != NULL && input_str[0] != '\n'){
            // read the first 10 chars & test conditions
        fputs(input_str, stdout);   // print them out
        while (getchar() != '\n'){   // discard leftover chars
            continue;
        }
    }

    puts("It's done");

    /*

    3// Alternative to gets(): gets_s()
        we have gets_s() that can also limit the number of char read.

        gets_s() vs fgets()
        gets_s(input_str, STRLEN)
            - only read from stdin, so no 3rd arg for input file
            - when coming into a newline, gets_s() read it too, but gets_s() discard it
                    rather than store it like fgets()
              Thus, if the input str isn't too long, gets_s() behaves like gets()
            -
        BUT FOR SOME REASON, THERE IS NO GETS_S()


    4// Alternative to gets(): a DIY s_gets()
        s_gets(input_str, n) is a smarter string getting function. It can
            - take in a "char array name" (pointer) to store the input_str, take in an int n indicating the length of str
            - If line length <= n, read the whole line and replace '\n' with '\0' to create a string.
            - If line length >  n, read n char (read n+1, replace last one with '\0') and discard the rest.

        The following two functions: s_gets_myver() and s_gets() function this way.

        By making of the NULL pointer, we can use the returned value of s_gets() as a flag for empty input.
    */

    char input_str_2[20];
    int n = 3;

    printf("I'll print the first %d char of your input as a string. (my ver)\n",n);
    while (s_gets_myver(input_str, n)){
        puts(input_str);
        printf("A string has been printed.\n");
    }

    printf("I'll print the first %d char of your input as a string.(C Primer Plus ver)\n",n);
    while (s_gets(input_str, n)){
        puts(input_str);
        printf("A string has been printed.\n");
    }

    /*
    //5 scanf() with a "%s"
        We can also use scanf() with a placeholder "%s" to read a string
        scanf() is more of a "get word" than a "get string" function.

        How scanf("%s", myStr) functions?
            - scanf("%s", myStr)
                "Fibonacci numbers" --> myStr: "Fibonacci"
                                        queue: " numbers"
            - scanf("%5s", myStr)
                "Fibonacci numbers" --> myStr: "Fibon"
                                        queue: "acci numbers"
                "An apple"          --> myStr: "An"
                                        queue: " apple"
            In a nutshell, scanf() stop at specified char numbers
                or whitespace, whichever comes first.

        What does scanf("%s %s", myStr_1, myStr_2) return?
            Same as before, it returns #successfully read strings

        rmk. For count = scanf("%2s %3s", myStr_1, myStr_2),
               input            count      myStr_1     myStr_2      queue
            "an apple"            2         "an"        "app"       "le"
            "two apples"          2         "tw"         "o"      " apples"
            "noapple"             2         "no"        "app"       "le"

            Follow the "In a nutshell" above, and you will rationalize these three examples.
                or maybe you could just give it a shot using the function scanf_str() below.
    */
    scanf_str();

    /*
        You might have noticed that scanf isn't that easy-to-use when dealing with string
            In fact, fgets() is a better choice if you wanna read a line of string.

        The typical use for scanf() is reading
            and converting a mixture of data types in some standard form.
            e.g. make a list of names of fruit.

        Note that without specifying the field length ("%5s"),
            scanf() can cause an overflow same as gets() does.

    */













}
