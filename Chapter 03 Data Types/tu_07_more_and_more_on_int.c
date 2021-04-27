#include <stdio.h>
/* Modifier of int type will be covered in this .c file*/

int main(void)
{
/*
Part 1. adj(modifier) of integer type
   modifier    explanation
    short     store small integer, need less memory, a signed type (16-bits)
    long      store large integer, need more memory, a signed type (32-bits)
  long long   larger than long, use at least 64bits, a signed type (64-bits)
                                                    rmk. int   (16- or 32-bits)
   unsigned   for nonnegative integers ( >= 0), use another digit to save sign
                which allow a larger integer
    signed
*/
    printf("The size of long long integer 7LL is %d bytes, %d bits\n", sizeof 7LL,(sizeof 7LL)*8);
    // Append L (LL/ U) to store a short int as a long int (long long int/ unsigned int)
    // e.g. 54L, 109LLU, 87ULL
    unsigned int a = 1000;
    unsigned int b = 42;
/*
Part 2. printing these integer types
  modifier     placeholder (lowercase only)
    short          %h
    long           %l
  long long        %ll
   unsigned
    rmk. if combined with number base, then long base
    e.g.  %llu := long long unsigned integer
          %hx  := short integer in base-16


*/

    printf("a + b = %d", a+b);
    return 0;
}
