#include <stdio.h>
/* A pointer is a variable whose value is the address of another variable, i.e. contain the direct address of the memory location*/
// int * p_A = &A;
// B = * p_A;
// & A   == to get the address of variable A
// * p_A == to get the value of variable A whose address is in pointer p_A

/* Note that there are different types of pointers for different data types. e.g integer pointer for integer */




void change_c(void)      /* change c by assigning a new value directly to its memory location*/
{
    int c;
    c = 3;
    printf("c = %d\n",c);
    printf("Enter c: ");
    scanf("%d",&c);     /* ask for keyboard input, then store the input into the address of c  (&c) */
    printf("c = %d\n",c);
}



void no_swap(int a,int b)
{
    int mid;
    mid = a;
    a = b;
    b = mid;
    printf("Inside the function no_swap(a,b),\na = %d\nb = %d\n",a,b);
}
/*
This function won't work b/c when we run the function, C will make a copy of a and b, and our function only works on this copy,
it won't change the value of the variable outside the function.
*/

/* To change the value of a and b, we can refer to their pointers in the function swap(a,b)*/

void swap(int * pointer_a, int * pointer_b)         /* swap the addresses of two variables a and b*/
{
    int mid;                                         // C makes a copy of pointer_a and pointer_b, but this doesn't matter,
    mid = * pointer_a;                               // b/c the content of a pointer is merely an address,
    * pointer_a = * pointer_b;                       // we can refer to the content of the address by *pointer_a
    * pointer_b = mid;                               // Here, we can use mid to store the value of a temporarily.

}



void main(void)
{
    change_c();
    int a,b;
    int * pointer_a;
    int * pointer_b;
    printf("\nEnter a:  ");
    scanf("%d",&a);
    printf("\nEnter b:  ");
    scanf("%d",&b);
// an incorrect swapping function
    no_swap(a,b);
    printf("But outside the function no_swap(a,b), \na = %d\nb = %d\n",a,b);
// a correct swapping function
    pointer_a = &a;
    pointer_b = &b;
    printf("but if our input are their pointers, we can then swap *pointer inside the function");
 //   printf("\na = %d,b = %d",a,b);
    swap(pointer_a,pointer_b);
    printf("\na = %d\nb = %d",a,b);
}

