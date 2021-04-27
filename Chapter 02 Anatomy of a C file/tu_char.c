/* You can write comment in C in this way*/
// Or in this way (in which one can only write comments in one line)
/* include is a preprocessor instruction
   to include <stdio.h> is to include(cut and past) all info in stdio.h */
#include <stdio.h>
/* stdio = Standard (support for) (keyboard)Input and (display)Output. */
#include <stdlib.h>
/* stdlib = Standard Library*/

/* functions(fn.s) are the basic modules of a C program */

int main(void)              /* fn main() is what will run when you click the run button
                           it must be after the declaration of all other fn.s mentioned in main()
                           int indicates that main() will return an integer to the operating system
                           main(void) indicates fn main() need no argument
                           main() can also work, but main(void) is the standard practice (therefore the best)*/
{                       /* "{" indicates the start of a fn's statement
                           "}" indicates the end of a fn's statement */

/* There are five types of statement in C:
    declaration,
    assignment,
    function,
    control,
    null
*/
    int characterAge;                               /* a declaration statement:  declare the name and data type of a variable*/
    char characterName[] = "AAAAAAhnathan";         /* always choose a MEANINGFUL name for a variable*/
    characterAge = 70;                              /* an assignment statement:  assign value 70 to variable characterAge */
    /* rmk: since we declare characterAge as an integer,
       even if we let characterAge = 70.54,
       the value assigned to that variable will still be 70. */

    /* if compiled in older version of C, all declaration statements must be placed at the very beginning
       so if in old C, this program won't work if I switch line 28 with line 27
       but if in C99, it will still work, though not recommended (see C_Primer_Plus.pdf p27)*/

    printf("My name is %s\t",characterName);        /* a function call statement*/
/* %s in printf = a placeholder for string: "%" tell C where to insert a variable, "s" tells C to print the variable as a string
   %d in printf = a placeholder for integer */
    printf("You can call me John\n");
/* \n means start a newline
    it's one of the escape sequences (things one can't type in the code: \t:tab, \b:backspace)*/
    printf("I'm %d years old.\n\n",characterAge);
    /* "d" tells C to print the variable as a decimal(base 10)
    characterAge = 20;
/*  You can change the content of variable halfway.*/
    printf("And my name is Joe\n");
    printf("I'm %d years old too.\n",characterAge);

    return 0;
}
