
/*This .c file talks about type specifiers in ANSI C. */

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
/*
A variable is characterized by its type and storage class.
    There are several more properties: const
                                       volatile
                                       restrict
                                       _Atomic (in stdatomic.h)

    By using these keywords, we can create qualified types

Type qualifiers are idempotent, i.e. const const int a <==> const int a.

1/ const
    const int foo = 2; means that foo is immutable and readable-only.

    1// const pointer and pointer of const value
        It's quite tricky when using const with pointers, you need to distinguish what is
            const: the pointed object or the pointer itself.

        e.g.
        const float * pf;   // equiv, float const *pf
        // pointed object is const, it reads constant float pointer,
        //      pf points to a constant float.
        //      value of pf (the pointed address) is mutable, value pointed by pf is immutable

        float * const pt;
        // pointer is const, reads float pointer
        //      pt points to a float, and pt is const
        //      value of pt is immutable, value pointed by pt is mutable.

        const float * const pft

        To sum up, const to the left of * means pointed-to value is const
                   const to the right of * means pointer is immutable

        We can apply const to formal parameters to avoid mistakes.
        e.g.
        When passing an array to a function, we pass the pointer. This allows the function
            to change the value of the array. If we want the value to be read-only to the function,
            we can declare the formal para (pointer) as a pointer of const value

        void display(const int arr[])
        char strcat(char * restrict s1, const char * restrict s2)
            // prototype of strcat(s1, s2), cat s2 to s1, change s1, won't change s2

        We can illustrate such diff with error raised for two types of pointers
        e.g.
        const int num_1 = 11;
        int num_2 = 22;
        int num_3 = 33;
        const int * ptc = &num_1;
        int * const cpt = &num_2;

        *ptc = 111;   ==> error: assignment of read-only location '*ptc'    // pointed value is const
        cpt = &num_3; ==> error: assignment of read-only variable 'cpt'     // pointer is const



    2// Using const with global variable
        Global variables can be mistakenly altered by any part of the program b/c it's exposed to the whole program.
            Making it a const can avoid such risk.

        To share const global variable between files, there are 2 approaches:
        /1  extern
            == file1.c --defining declaration ==
            const char * WEEKEND[2]=  {"Sat", "Sun"};

            == file2.c --reference declaration ==
            extern const char * WEEKEND[];

        2/ include
            == constant.h --defining declaration ==
            static const char * WEEKEND[2]=  {"Sat", "Sun"};

            == file1.c --include header file ==
            #include "constant.h"

            == file2.c --include header file ==
            #include "constant.h"

            The keyword static in approach 2 is important. By making the linkage of WEEKEND internal,
                it allows each file to create its own copy of WEEKEND. W/o static, the linkage is external
                and there will be two defining declaration of the same variable in file 1 and file 2, which is problematic.

            pros: ez to use, no need to do reference declaration in each file when using the global var
            cons: need to copy the data, which is troublesome when the global var is enormously large

2/ Volatile and caching
    A volatile variable is one whose value can be altered by agencies other than the program (like other computers).
        Volatile is used for compiling optimization.

    To cache a variable is to store it in register for quick access. If that variable changes, then caching will be problematic
        for the value stored in register won't change along. Qualified by volitile, the compiler knows that the variable will change
        during use and won't cache it.


3/ Restrict
    restrict can be applied to pointer only. It makes a pointer the sole initial means of accessing a data object.

    UNFINISHED, TOO BORING
*/



    return 0;
}
