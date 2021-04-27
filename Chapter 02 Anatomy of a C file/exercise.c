#include <stdio.h>
#include <stdlib.h>

void one_three(void);
void two(void);

void one_three(void)
{
    printf("one\n");
    two();                  /* You can call a fn in a fn. */
/* Additionally, if you change two() into one_three() here, the program
   will recurse forever, and we call this a recursion */
    printf("three\n");
}

void two(void)
{
    printf("two\n");
}

void main(void)
{
    printf("\n");
    printf("starting now:\n");
    one_three();
    printf("done!");
    printf("\n");
}
