#include <stdio.h>

/* This .c file is a continuation of tu_array_1.c */

/*Part 1: Argument and Parameter*/
// Argument:  actual argument
// Parameter: formal argument
// Difference: Parameter is the names of values that are supplied by some variables, to define a fn, use myfunc(Parameter)
//             Argument is the names of values that are provided for other variables, to  call  a fn, use myfunc(Argument)
// Note: To pass a value from an argument (outside the function) to a parameter (inside the function),
//       you must make sure the argument and the parameter are of same data type.


void recap_of_pointer(void);
double getAverage1(int arr[],int size);
double getAverage2(int * lo_arr,int size);
int sumArray(int *lo_arr);


int main(void)
{
/*Part 1.5: Recap on Pointer*/
    recap_of_pointer();

/*Part 2: How to pass an array to a function? */
    int s = 6;
    int myArray[6] = {1,2,3,4,5,6};
// "int myArray" defines an integer array argument, which provides sub_functions with values to give to their parameters)
    int *lo_myArray = myArray;
// The line above is equiv to "int *lo_myArray = &myArray", b/c RHS of both are the address stored in a pointer

    double averageMyArray;

    averageMyArray = getAverage2(lo_myArray,s);                                // method 1: para = int *array
    printf("The average of my array is about %.2f\n\n",averageMyArray);

    averageMyArray = getAverage1(myArray,s);                                   // method 2: para = int array[] (method 3 ÂÔ)
    printf("The average of my array is about %.2f\n\n",averageMyArray);


/*Part 3: Multi-dimensional array*/

    int myArray2d[3][4] =           // declare a multi-dim array
    {
        {0,1,2,3},                  // the braces inside braces are omissible, i.e. this declaration statement is equiv to
        {4,5,6,7},                  // int a[3][4] = {0,1,2,3,4,5,6,7,8,910,11}
        {8,9,10,11}
    };

    int i=0,j=0;
    printf("My 2d array looks like:\n");
    int *lo_myArray2d;
    lo_myArray2d = myArray2d;
    for (i = 0; i<3; i++)
    {
        for (j = 0; j<4; j++)
            {
                printf("%d ",*(lo_myArray2d+i*4+j));  // equiv to "printf("%d ",myArray2d[i][j]);"
            }
        printf("\n");
    }
    int sumMyArray2d = sumArray(myArray2d);
    printf("The sum of my 2d array is %d\n\n",sumMyArray2d);

    return 0;
}


/*Part 1.5: Recap on Pointer*/
void recap_of_pointer(void)
{
    int a;
    int* Loa;   // define an integer pointer variable (who points to the location of an integer variable)
    a = 114514;
    Loa = &a;   // use "& variable" to get the location of that variable
    printf("a = %d\n",a);
    printf("a = %d\n",*Loa);    // use "* pointer_a" to get the value stored in the location pointed by pointer_a.
    printf("a = %d\n",*&a);
    printf("a is stored in %d\n",&a);
    printf("a is stored in %d\n",Loa);
    printf("a is stored in %d\n",&*Loa);
    printf("Pointer of a is stored in %d\n",&Loa);
    printf("But a isn't stored in %d\n\n",&Loa);

}

/*Part 2: How to pass an array to a function? */
// To pass an array to a function, we have 3 methods
// set the parameter to be a pointer                        void myFunction(int* pointer_of_BB)
//                         an array with defined size       void myFunction(int BB[5])
//                         an array with undefined size     void myFunction(int BB[])

double getAverage1(int arr[],int size)
// "int arr[]" defines an integer array parameter, which accepts the value given from outside.
// This parameter is defined in the () of the function in its declaration statement.
{
    int i;
    double avg;
    double sum;
    sum = 0;
// It's extremely important to initialize sum (sum = 1), otherwise, C will store the value of sum
    for (i = 0; i < size; ++i)
    {
        sum += arr[i];    // this line is equivalent to  "sum += *(arr+i);"
    }
// printf("sum of myArray is %.2f\n",sum);      bug here, without this line and the "sum = 0" above, the output will bestrange
    avg = sum/size;
    return avg;
}

double getAverage2(int * lo_arr,int size)   // getaverage1() <==> getaverage2()
// "int arr[]" defines an integer array parameter, which accepts the value given from outside.
// In fact, getaverage2(arrayName, size) also work for this function
// This parameter is defined in the () of the function in its declaration statement.
{
    int i;
    double avg;
    double sum;
    sum = 0;
// It's extremely important to initialize sum (sum = 1), otherwise, C will store the value of sum
    for (i = 0; i < size; ++i)
    {
        sum += *(lo_arr+i);    // this line is equivalent to  "sum += *(arr+i);"
    }
// printf("sum of myArray is %.2f\n",sum);      bug here, without this line and the "sum = 0" above, the output will bestrange
    avg = sum/size;
    return avg;
}


// Part 3: Multi-dimensional array
// Above are all one-dimensional array, in C we can also define multi-dimensional array
int sumArray(int *lo_arr)   // use arrayName as parameter
{
    int sum = 100;
    int i,j;
    for (i = 0; i<3; i++)
    {
        for (j = 0; j<4; j++)
            {
                sum += *(lo_arr+i*4+j);
            }
    }
    return sum;
}

