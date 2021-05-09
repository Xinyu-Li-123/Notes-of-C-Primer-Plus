#include <stdio.h>
#include <string.h>
#define WORDCOUNT 5
#define WORDSIZE 40

/* Part 3. String Output
    1// puts()
        puts() stop reading whenever encountering a null char ('\0')
        puts() will automatically append a '\n' to the printed string

    2// fputs()
        fputs(str, location): second arg indicates where to write
        fputs() won't append '\n'

        rmk. two pairs of get & put
             gets() discards '\n', puts() appends '\n'
             fgets() stores '\n', fputs() doesn't append '\n'

    3// printf()
        ...

    4// DIY
        int myput(const char *input_str)
        - print input_str w/o appending '\n'
        - return #char in input_str
*/

void fit(char *input_str, int size)     // shorten an array string
{
    if (strlen(input_str) > size){
        input_str[size] = '\0';
    }
}



int myput(const char *input_str);
char *s_gets(char *input_str, int n);
char *sort_strings(char *input_str);



int main(void)
{
    const char *input_str = "abcdefg";
    int i = myput(input_str);
    printf("\nThere are #%d char in the string %s.\n", i, input_str);
    printf("%d\n", strlen(input_str));


/* Part 4. String Functions
    There are many string-handling functions in string.h. We will look at
        some of the most useful ones.

    1// strlen()
        strlen(input_str) returns the length of input_str
        e.g. fit()  // shorten a lengthy string
*/

    char myStr_1[] = "Why does the sun go on shining? "
    "Why does the sea rush to shore? ";

    puts(myStr_1);
    fit(myStr_1, 10);
    puts(myStr_1);

/*
    2// strcat()
        strcat() is for string concatenation.

        strcat(str_1, str_2) append str_2 to str_1
            - It won't change str_2.
            - It will change str_1 (appending)
        e.g.
            char str_1[] = "Hello";
            char str_2[] = "world!"
            strcat(str_1, str_2);
            puts(str_1);    // >> "Hello world!"
            puts(str_2);    // >> "world!"


    3// strncat()
        Similar to gets(), strcat() can't check
            - if the second str fits into the size of the first str
            - if buffer overflows

        (But diff from gets(), the danger of strcat() is a result of careless programming.
            Thus, the C philosophy believes in programmers
            and reserve this dangerous and convenient strcat():)

        Similar to fgets() to gets(), we have strncat() to strcat()

        strncat(str_1, str_2, 10)
            - will append first 10 char of str_2 or char before '\0',
                    whichever comes first.
*/
    char myStr_2[] = "Thunder";
    strncat(myStr_2, "struckkkkkk", 6);
    puts(myStr_2);

/*
    4// strcmp()
        strcmp(str_1, str_2) is for string comparison

        One of the nice features of strcmp() is that it compare strings, not arrays.
        i.e. it can compare same strings stored in arrays of diff sizes

        It stop comparison when reaching a '\0'

        returned value of strcmp(str_1, str_2)
                    if                         then
        str_1 == str_2 (all char are equal)     0
        ASCII(*str_1) > ASCII(*str_2)            1  (or other positive int)
        ASCII(*str_1) < ASCII(*str_2)            -1 (or other negative int)

        rmk. if first char equal, second not, then compare the second char.

        e.g. char foo[10] = {'A','B','C','\0'}
             strcmp("ABC",  foo ) == 0
             strcmp("A",    "A" ) == 1
             strcmp("ABC",  "D" ) == -1
             strcmp("ABC", "ABD") == -1
             strcmp("ABC",  "A" ) == 1  // second char of str_2 is '\0' (?)
             strcmp(".ABC", "ABC")== -1 // strcmp compare all chars (in this case, '.'),
                                        //      not just letters

*/
    char myStr_3[40] = "Thunder""Struck";
    char myStr_4[40];

    /* An application of strcmp(): to test if two strings are identical */

    i = 3;
    printf("One ___ a day, keep the doctor away. You have %d guesses: ", i);
    for (i = 2; strcmp("apple" , s_gets(myStr_4, 10)) && i > 0; ){
        printf("\nNope. You have %d guesses: ", i);
        i--;
    }
    if ( i <= 0 && strcmp("apple" ,myStr_4))
        printf("\nYou've run out of guesses\n");
    else if (!strcmp("apple" , myStr_4))
        printf("\nYou made it!\n");
    printf("\ndone.\n");

/*
    5// strncmp()
        strncmp(str_1, str_2, n)
        limit char comparison to the first n chars.

        e.g. comparing the first 5 letters of two strings
        strncmp("Applepie", "Applejuice", 5) == 0
        strncmp("Applepie", "Applejuice", 6) == 1


    6// strcpy()
         "char pt1[] = "abc"; char *pt2 = pt1;" only copy the pointer
         To copy a string, we need strcpy()

         strcpy() is the string equivalent of the assignment operator
         strcpy(str_1, str_2) means
            assigning string pointed by str_2
                   to str array pointed by str_1
            (assignment goes from right to left)

         str_1 (the copy)           is called the target
         str_2 (the original string)is called the source

         e.g. A program that only accept words starting with 'q'
*/

    char myStr_5[WORDCOUNT][WORDSIZE];
    char temp[WORDSIZE];
    printf("Enter %d words that start with q.\n", WORDCOUNT);

    while (i < WORDCOUNT){
        printf("\n\nword #%d: ", i+1);
        s_gets(temp, WORDSIZE);
        if (temp[0] == 'q'){
            strcpy(myStr_5[i], temp);
            i++;
        }
        else printf("%s doesn't start with q!", temp);
    }
    printf("\n%d words accepted:\n", i);
    for (i = 0; i < WORDCOUNT; i++){
        puts(myStr_5[i]);
    }

/*
        prop of strcpy()
        -   it returns a char pointer of the first char of str_1
        -   str_1 need not point to the beginning of a string


    7// strncpy()
        strcpy() bears the same risk as strcat()
            If target has a smaller size than that of source, lose info

        As usual, we have strncpy() that specify how many char in source
            do you wanna copy

        e.g.
        const char *myStr = "abcdefg"
        char ps[4];
        strncpy(ps, myStr, strlen(ps));

    e.g. A program that use both strcpy() and strncpy()
*/
    const char *myStr_6 = "Hello, I'm here.";
    char *ps;
    int n = 5;
    ps = strncpy(temp, myStr_6,n);
    // Both strcpy() and strncpy() return a pointer of str_1
    temp[n] = '\0';
    puts(ps);
    strcpy(temp + n, myStr_6 + 7);  // overwrite the '\0'
    // strcpy() need not start copying/ pasting from the first char
    puts(temp);


/*
    8// sprintf()
    sprintf() can write formatted string into a container of string.
    It's in stdio.h instead of string.h.

    sprintf(address_of_target, "prompt", placeholders);

    e.g.
*/

    sprintf(temp + 7, "have a %s", "pie");
    puts(temp);






    return 0;
}

int myput(const char *input_str)
{
    int i;
    const char *str = input_str;  // create a temp pointer for printing
    for (i = 0; putchar(*str); str++, i++);
    // as a test condition: *str <==> putchar(*str) <==> (*(str) != '\0')
    return i;   // i = #char in input_str
}



char *s_gets(char *input_str, int n) // see tu_02_string_input.c
{
    int i = 0;
    char *ret_val;
    ret_val = fgets(input_str,n + 1,stdin);
    if (ret_val){
        while (input_str[i] != '\n' && input_str[i] != '\0')
            i++;
        if (input_str[i] == '\n')
            input_str[i] = '\0';
        else{
            while (getchar() != '\n')\
                continue;
        }
    }
    return ret_val;
}

