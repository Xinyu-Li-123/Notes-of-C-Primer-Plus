#include <stdio.h>
#include <string.h>
/* This .c file will cover more knowledge on type int*/
/*
Part 1. Keywords
1/ int
2/ float, double
3/ long, short, unsigned, signed
    (variation before other data type)
4/ char
5/ void
6/ _Bool, _Complex, _Imaginary

e.g.
unsigned short int a=3;
*/

/*
>>Extra. Bits, Bytes, and Words
    All three refers to units of computer memory
1. bit: the smallest unit of memory, only hold two values: 0 or 1
2. byte: the usual unit of computer memory. Conventionally, 1 byte = 8 bits
3. word: the natural unit of memory for a given computer design
         There are 8-bits, 16-bits, 32-bits, 64-bits words computer
         Larger word sizes ==> faster transfer of data & more memory to be accessed
*/

/*
Part 2. Integer vs Floating-point Types
They are stored differently in the computer memory
e.g. integer:         7    ==> 111 (computer memory)
     floating-pt: 3.14  ==> 0.314E1 ==>  +    .314159      1      (computer memory)
                                       sign   fraction  exponent
rmk. 1. floating-pt number can have greater loss of precision than integer

*/

int main()
{
/* Part 3. Int*/
// 1. basic definition
    short A;
    int B;
    printf("please enter an integer A (base 10): ");
    scanf("%d",&A);
    printf("and an integer B (base 16):");
    scanf("%x",&B);
    // int a is a signed integer. It usually takes one machine word for storage
    int size = sizeof A;
    printf("The size of A = %d is %d bytes, %d bits\n",A,sizeof A,(sizeof A)*8);

    //if the integer is very large,
    // we will use long and long long for declaration

// 2. Octal (base 8) and Hexadecimal (base 16)
    // integers by default are decimal (base 10).
    // We can use special prefixes to indicate the number base.
    //   base      prefix         e.g.
    //    16      0x or 0X     16 ==> 0x10
    //     8         0         16 ==> 020
    // rmk. whichever number base, the number itself is stored in the same way, in bits

    // There are also placeholder for different bases in printf()
    //   base     placeholder
    //    10          %d
    //     8          %o
    //    16          %x
    //  (to print out the prefix, use %#o, %#x, %#X)
    printf("A = %d (base 10) = %o (base 8) = %x (base 16) = %#o = %#x\n",A,A,A,A,A);
    printf("0x15 + B = %#x\n",0x15+B);    // addition in base-16
    return 0;

/* */
}
