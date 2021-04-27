#include <stdio.h>
#include <complex.h>

/*
float representation is similar to scientific notation
e.g. 120000 = 1.2 * 10^5 = 1.2e5

a is float, then a is in [10e-37, 10e37]
*/

int main(void)
{
/* Part 1. float and double */
    float a = 1.232343e1;
    // float can preserve [insert 6 significant numbers] e [insert sign + or -] [insert 3 significant numbers]
    double b = 1234.567876543;
    // float can preserve [insert 10 significant numbers] e [insert sign + or -] [insert 3 significant numbers]
    printf("a = %f, a can be written as %e, a is float\n",a,a);
    printf("b = %f, b can be written as %e, b is double\n",b,b);

    // overflow: the number is too big
    printf("1e30000 is too big for the computer to handle. It will be printed as %f\n",1e30000);

    // underflow: the number is too small
    printf("1e-30000 is too big for the computer to handle. It will be printed as %f\n",1e-30000);


/* Part 2. complex and imaginary types*/
    // to use complex number in C, include complex.h
    float complex z1 = 12.234 + 3.234*I;
    // If complex.h is included, then I = (-1)^0.5
    printf("z1 = %.2f + %.2fi\n",creal(z1),cimag(z1));
    float complex z2, z3;
    z2 = z1*z1;
    z3 = I*I;
    printf("z2 = z1 * z1 = %.2f + %.2fi\n",creal(z2),cimag(z2));
    printf("z3 = %.2f + %.2fi\n",creal(z3),cimag(z3));
    return 0;

/*
remark: Other data types(array, pointer, structure, union)
        are derived from basic data types(int, char, float, double)
*/
}
