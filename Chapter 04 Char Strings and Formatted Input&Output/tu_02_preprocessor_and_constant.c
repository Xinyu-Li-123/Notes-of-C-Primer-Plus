#include <stdio.h>
#define MYCAKE "BEST CAKE EVER!!"
/* Part 1. preprocessor: define  and  manifest constant */
    // use preprocessor define to define a CONSTANT string: #define c_name c_value
    //      if it's a constant, then it's only readable. You can't modify it in the program
    // predefined constant will substitute c_name for c_value before compiling ,
    //      therefore we call it "manifest constant"
    // e.g. char MYCAKE[5] = "BEST CAKE EVER!!"
#include <limits.h>
    // limits.h contains CONSTANTS of min and max of various data types
    // e.g. CHAR_MIN := Maximum char value
#include <float.h>
    // max and min of float, double etc
int main()
{
    printf("Tell me something about your cake.\n");
    printf("%s\n",MYCAKE);

/* Part 2. Symbolic Constant*/
    const float PI = 3.14159;
    // use const c_type c_name = c_value to define a constant in C
    // Conventionally, we use capitalized letters to represent constants
    float radius, C, S;
    printf("Please enter the radius of your pizza (cm): ");
    scanf("%f",&radius);
    C = 2 * PI * radius;
    S = PI * radius * radius;
    printf("The value of pi is about %.4f\n",PI);
    // %.4f := round off at 4th decimal
    printf("The circumference of your pizza is %.2f cm\n",C);
    printf("The size of your pizza is %.2f cm^2\n",S);
    printf("The maximum value of a character is %f\n",CHAR_MAX);
    printf("The maximum value of a character is %f\n",CHAR_MAX);



    return 0;
}
