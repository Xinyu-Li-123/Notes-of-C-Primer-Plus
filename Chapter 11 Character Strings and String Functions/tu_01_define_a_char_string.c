#include <stdio.h>

#define MYSTR "This is a predefined string."

void main(void)
{

/* Part 1. Define strings within a program
1/ String Literal
    A string literal (string constant) is anything enclosed in the double quotation.

    It is a constant, thus unmodifiable.

    String literal belongs to the static storage class.
        Once created in a program, C will store it in the static storage.
        It will stay in the same address till the end of the program

    The name of the literal can be used as a pointer,
        similar to the way an array name functions


2/ How to define a string: Array vs Pointer
    0// recap: string
        A string is an char array that ends with a null char '\0'
        i.e.  "abc" == {'a','b','c','\0'}

    1// Character String Arrays
        We can use a char array that ends with '\0' to define a string  */

    char word1[4] = {'a','b','c','\0'};
    char word2[] = {'a','b','c','d','e','\0'};
    char arr_str[] = "Hello world!";

    /*  It's convenient not to specify the string length
            b/c with '\0' char, it's easy for computer to decide the lenght

        If we initialize a char array with a string literal,
            C will make a copy from the static storage to the array
            Thus string defined this way is not a string literal but a char array
            It is therefore modifiable

    2// Pointer
        We can use a char pointer to define a string    */


    const char *ptr_str_1 = "Hello world!";
    const char *ptr_str_2 = "Hello world!";


    /*  What we are doing is not create a new string,
            but saving the address of one string literal into different char pointers
            ptr_str_1 and ptr_str_2 point to the first char of the string literal "Hello world!"
                and t/f point to the string "Hello world!"

        To be more rigorous, we actually define a const char pointer. The proper declaration should be

        const char *ptr_str_1 = "Hello world!";

        ptr_str_1 is a "const char pointer"
            not in the sense that ptr_str_1 is a constant (unmodifiable)
            but in the sense that it points to a constant string (string literal)
                And thus we can't modify the string by referring to pointer ptr_str_1

        It's more burdened for C to copy the entire string literal.
            In many occasion, A copy the address is enough.

        Illustrative example:
        In the example below, you will find that the address of "Hello world!",
            ptr_str_1, ptr_str_2 are the same, different from that of arr_str*/

    puts("Hello world!");   // puts(string) is a function that print out string with a newline. It belongs to stdio.h
    printf("string literal   : %p\nchar array string: %p\npointer string 1 : %p\npointer string 2 : %p\n","Hello world!",
           arr_str, ptr_str_1, ptr_str_2);


    /*
    3// Array vs Pointer
        Difference:
                        Array                               Pointer

            copy the whole string literal        copy the address of the string literal

                   arr[i] modifiable                  *ptr not modifiable

                   arr unmodifiable                     ptr modifiable

        e.g.
                        valid                               invalid

                ptr_str_1 = arr_str;                   arr_str = ptr_str_1;

                arr_str[1] = *(ptr_str_1+3);            *(ptr_str_1+1) = *(arr_str+2);

                ++ptr_str;                                 ++arr_str;
            (point to 'e', originally point to 'H')


3/ Array of char strings
    we can define an array of string by     */

    /* Method 1: define an array of pointer
    Occupy less memory (only store pointers in array)
    Can't modify the content of each string
    --> useful when no need to alter the array  */

    char *pros[3] = {
        "Easy to use",
        "Cheap",
        "Light"
    };


    /* Method 2: define an array of char array
    Occupy more memory (store strings in array)
    Can modify the content of each strings
    --> useful when no need to alter the array*/

    char cons[3][40] = {
        "Low life span",
        "Too noisy",
        "Hard to maintain"
    };

    printf("\nPros:\n%s\n%s\n%s\n",pros[0],pros[1],pros[2]);
    printf("\nCons:\n%s\n%s\n%s\n",cons[0],cons[1],cons[2]);

    printf("\nsizeof pros: %zd\nsizeof cons: %zd\n",sizeof pros, sizeof cons);
    // pros is an array of 3 pointer, t/f size = 3 * 4 (each pointer is 4 bytes) = 12
    // cons is an array of 3 char arrays, each contains 40-char, f/g size = 3 * 40 = 120









}
