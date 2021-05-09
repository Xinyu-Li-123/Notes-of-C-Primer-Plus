#include <stdio.h>
#include <stdlib.h>
/*
    Extra: stdlib.h
    atoi()   : alphanumeric to integer, convert string to integer
    atof()   : alphanumeric to double
    atol()   : alphanumeric to long
    strtol() : string to long,          with a specified base
    strtoul(): string to unsigned long, with a specified base
    strtod() : string to double         (no specified base)


*/


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

void main(void)
{

/*
    1// atol()
        prototype:
            long atol(const char *nptr);

        return 0 if the conversion fails (in fact, it's an undefined behavior)
            (thus atol("0") is indistinguishable from atol("word"))

        rmk. atol() stop conversion when it reads no num.
                thus  atol("69 Rocket") returns the long 69
                while atol("Rocket 69") returns the long 0 (probably)

*/

    char num_str[2] = "0";
    int i;
    puts("\n======== Enter a number to print some * (newline to quit) =======");
    while (0**(num_str)){
        puts("Please enter a number (1-99): ");
        s_gets(num_str,2);

        if (atoi(num_str)){
            printf("Your input is: %s\n", num_str);
            for (i = 0; i < atoi(num_str); i++)
                // atoi: alphabet to integer, in stdlib.h
                printf("*");
            puts("\n");
        }
        else if(*(num_str) != '\0'){
            puts("Invalid input.\n");
        }
        else{
            puts("You choose to exit.\n");
            break;
        }
    }
    puts("The end.");

/*
    2// strtol() vs atol()
        prototype:
             long strtol(const char * restrict nptr, char ** restrict endptr, int base);

                nptr   : point to the string to convert
                endptr : point to a pointer that points to where the conversion stop
                            (pointer of char pointer !!)

                        WTF ?????? why ** ????????

                base   : base of the converted number

             rmk. restrict means the object
                    can only be pointed by this specific pointer (C only)

        strtol() provides error-checking and base conversion.
            It's a more reliable and flexible choice than atoi()

        strtol() can identify and report the first character
            in the string that is not part of a number

        e.g.
*/
    char input_str[12];
    long num;
    char *end;
    printf("Enter a number: ");
    while (s_gets(input_str, 6)){
        num = strtol(input_str, &end, 10);
        if(*end){
            printf("Input number: %d\nReading end at %c (%p)\n\n", num, *end, end);
        }
        else{
            printf("Input number: %d\n\n", num);
        }
        printf("Enter a number: ");
    }







}
