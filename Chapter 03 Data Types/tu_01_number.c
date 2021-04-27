# include <stdio.h>
# include<stdlib.h>
/* We will introduce basic data types in this file*/


int gcd(int a,int b)
// gcd(a,b) := the greatest common divisor of a and b.
// apply the Euclidean Algorithm
{
    int gcd_ab;
    int temp = 1;
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


int main()
{
    int a,b;                         // declare a variable to be an integer
    // To assign a value to a variable, one can use a direct assignment statement
    // or get the value from user's input
    printf("Please type in integer a: ");
    scanf("%d",&a);
    printf("Please type in integer b: ");
    scanf("%d",&b);
    // scanf("%d",&var_name):= store the input into the location of var_name
    //                          i.e. assign the input value to var_name
    int gcd_ab = gcd(a,b);
    printf("The greatest common divisor of a = %d and b = %d is %d\n",a,b,gcd_ab);
    printf("By some knowledge of math, the least common multiple of a = %d and b = %d is %d\n",a,b,a * b / gcd_ab);
    printf("a is %d in base 10\nais %o in base 8\na is %x in base 16",a,a,a);
    // placeholder for base 2  : NONE FOR BASE-2
    //                 base 8  : o
    //                 base 10 : d
    //                 base 16 : x
    return 0;
}
