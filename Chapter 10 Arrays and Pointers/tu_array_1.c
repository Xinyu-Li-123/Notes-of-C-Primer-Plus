
/*This .c file covers the basic knowledge of array and the links between array and pointer in C*/

/* An array is an ordered list of same types of variables.
   Variables code-ly stored in an array are physically stored in neighboring memory locations,
     where the first location represents the first element of the array */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkGPA(void)
{

/* Part 1: Basic concepts of Array*/

// To declare an array, we use the following command
//      type arrayName [arraySize] = {initial data (optional};
// Here, we declare a one-dimensional array (the GPA of 5 students)
double GPA [5] = {3.6,3.5,3.0,3.8,3.2};                                     // Array declaration & initialization
printf("The GPA of 1st student in the Fall semester is %.2f.\n",GPA[0]);    // Array accessing
// To use the variable stored in an array, use arrayName[ordinal number]
// Note that C start counting from 0, not 1 !!!
// %f is the placeholder for float variable, %.2f means save 2 digits of decimal
GPA [0] = 3.8;                                                              // Array assignment
printf("And in the Spring semester, she got a %.2f.\n",GPA[0]);

}

void apple()
{

/* Part 2: Array and Pointer */

    int appleSell[5] = {23,21,15,26,33};     //  How much apple is sold from Monday to Friday
//  The name of an array is also a variable.
//  It is a pointer pointed at the location of the 1st element in that array
    int *LoMon ;            // A pointer pointed at the memory location of Monday selling
    LoMon = appleSell;      // This line is legitimate b/c both sides are integer pointers
    printf("Data of Monday's selling are stored in %p\n",LoMon);
    printf("%d apples were sold on Tuesday.\n",*(appleSell+1));
// Same as the syntax of pointer, we can use *(pointer+1) to access the data stored in appleSell[1]
// Here, with *(appleSell+1), we access the data stored in the 2nd elements of array appleSell.
    printf("%d apples might be sold on some random day.\n",*(appleSell+11));
// And in this case, we just access a random data stored 11 steps after

}


int * getRandom(void)
// int* is the declaration statement, it declares this fn to return an integer pointer
// This function can generate and return an array of andom number.
{

/* Part 3: How to let a function return an Array  */

// You can't let a function return an actual array, but you can instead return the arrayName (i.e. a pointer)

// Also, you can't return the address of a local variable outside the function,
//      unless you declare that local variable to be static variable
    static int r[10];                // declare a static integer array r with size 10
    int i;
    srand((unsigned)time(NULL));    // generate a random seed from line 61 to line , will be covered in the future
    for (i = 0; i < 10; ++i)        // a for loop, just pick it up.
    {
        r[i] = rand();
        printf("r[%d] = %d\n",i,r[i]+10000000);
    }

    return r;
}


int main(void)
{

    printf("\n");
    checkGPA();
    printf("\n");
    apple();
    printf("\n");
    printf("This is the random seed (+10000000) generated in function getRandom():\n");
    int * p;
    p = getRandom();        // pointer p = pointer r (r is returned by getRandom())
//    int AA = getRandom();
    printf("\nAnd below is what getRandom() returns (it's a pointer pointed at an 1*10 array, I name that pointer 'p'),\n\
I'll display it with a for loop:\n");
    int i;
    for (i = 0; i < 10; ++i)
    {
        printf("static_r[%d] = %d\n",i,*(p+i));
        //printf("static_r[%d] = %d\n",i,p[i]);
// Since r is a static variable, its values remain static in their locations assigned in getRandom()
// somehow, mysteriously, the cmd above will work even if I replace *(p+i) with p[i], but p should  be a pointer, not an array
    }
    printf("\n");
    return 0;
}
