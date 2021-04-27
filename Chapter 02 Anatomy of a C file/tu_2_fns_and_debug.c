
/* How to use two functions in one .c file */

#include <stdio.h>
#include <stdlib.h>
void butler(void);      /* function prototype (aka, declaration)*/
/*other fn.s', if used, must be declared before the main()
  but the location of their definition doesn't matter (both before main() and after main() are OK*/

int main(void)
{
    int cups, books;     /* This is a shorthand for "int cups; int books" */
    cups = 5;
    books = 3;
    printf("\nI will summon my butler function.\n");
    printf("ring...ring...\n");
    butler();           /* function call, tell the compiler to use the called function */
    printf("\nYes, bring me %d cups and %d books, please.\n",cups,books);
    return 0;
}

void butler(void)       /* function definition*/
{
    printf("You rang, sir?");
}

/*
How to debug?
I Syntax errors
1. Fix the first two errors
    When the compiler report bugs, don't fix all of them. You should fix the first several errors and recompile.
This is because one syntax error can lead to several errors, and once one is fixed, all are fixed.

2. Check one line before the error
    e.g. if there is a missing semicolon in line 5, the compiler will generally reports bug in line 6.

3. Avoid using keywords/identifiers as variables' names
    For the big list of keyword in C, see C Primer Plus

II Semantic errors
1. Execute by hand
    Write the structure of your program on a paper, go through it step by step (or first 3 iteration)

2. Additional printf()
    Add extra printf() to some fishy/important steps to see the evolution of a variable

3. Use a debugger
    There is a debugger in Code Blocks, but I don't know how to use it yet.
*/
