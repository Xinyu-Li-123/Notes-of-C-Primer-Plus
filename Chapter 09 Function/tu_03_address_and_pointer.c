/* This .c file covers: */


#include <stdio.h>
#include "hotel_info.h"

int showpooh(int i, int pooh)
{
    if (i <= 0){
        return 0;
    }
    else{
        printf("pooh = %d, stored in %p\n", pooh, &pooh);
        // %p is for pointer; address are normally hex
        i--;
        showpooh(i,pooh);
        return 0;
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{

/* Part 1. Using header file
    A simple practice in C or C++ programs is that we keep all the constants,
        macros, system wide global variables, and function prototypes
        in the header files and include that header file wherever it is required.

    Syntax:
        #include <sys_header.h>
            This form is used for system header file.
            It search for a file named 'sys_header.h' in a standard list of system directories.
            You can prepend directories to this list with the -I option while compiling your source code.

        #include "myHeader.h"
            This form is used for header files of your own program.
            It searches for a file named 'file' in the directory containing the current file.
            You can prepend directories to this list with the -I option while compiling your source code.





*/

    printf("%.2f\n",HOTEL1);
    int a = get_night();
    printf("a = %d",a);


/* Part 2. Address and Pointer
 A pointer is a variable whose value is the address of another variable,
    i.e. contains the direct address of the memory location

    &var: operator, return the adress of var
        (read: the address of variable var)
    *ptr: indirection operator, return the value of
            the variable whose address is stored in pointer ptr
        (read: the value of the variable pointed by ptr)

    e.g 1
        int A;
        int * p_A;      // this line means: the variable pointed by p_A is of type int.
        p_A = &A;
        B = * p_A;

        & A   == to get the address of variable A
        * p_A == to get the value of the variable pointed by pointer p_A

    e.g. 2
        ptr = &var1;
        var2 = *ptr;
        <==>
        var2 = var1;

    e.g. 3
        swap() // see the definition above
        We want to swap the value of two variable var1, var2 with a function.
            swap(var1, var2)    // NO!
            swap(&var1, var2)   // YES!
        In C, each function has its own variables, called local variables
        In case NO, the variable-swapping only take place inside the function
        In case YES, since we give the function address of var1 and var2,
            it can modify var1 and var2 inside by referring to *&var1, *&var2


    To communicate with a function (i.e. pass a value as its argument), one can:
        fun(var)      // pass the value of var to the function,    given void fun(int var_in_fun)
                      //    used for calculation based on the value of var
        fun(&var)     // pass the address of var to the function,  given void fun(int *ptr_in_fun)
                      //    used for alternating the value of var

*/

    int var1, var2;
    int *ptr;
    var1 = 12;
    ptr = &var1;
    var2 = *ptr;
    printf("\nvar1 = %d  \nvar2 = %d  \n&var1 = ptr = %p  \n*ptr = %d  \n*&ptr = %p  \n**&ptr = %d  \n", var1,
           var2,ptr,*ptr,*&ptr,**&ptr);

    int pool, bah;
    pool = 12;
    bah = 3;
    showpooh(5,pool);

    printf("pool = %d,  bah = %d\n", pool, bah);

    swap(&pool, &bah);
    printf("Swap!\nNow, pool = %d,  bah = %d\n", pool, bah);



/* Part 3. Names, Addresses, and Values
    For the programmer, a variable has a  name    and a value
    For the computer,   a variable has an address and a value
    (address is like the computer version of name)

    A regular variable makes its value the primary quantity and its address a derived
        quantity, via the & operator.
    A pointer variable makes the address of the pointed variable the primary quantity and the
        value a derived quantity, via the * operator.


 */



    return 0;
}
