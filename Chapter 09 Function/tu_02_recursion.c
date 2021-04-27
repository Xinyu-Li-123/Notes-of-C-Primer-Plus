#include <stdio.h>

/* Part 3. Recursion
    1/ Intro
        C allows a function to call itself. This is called recursion.

        Recursion often can be used where loops can be used.
        Recursive solutions tend to be more elegant and less efficient than loop solutions.

        2/ Examples
        e.g 1,
        the executing order of e.g.1 is as follow: (f_i: function f at level i)
        f_1 -> f_2 -> f_3 -> f_4 (if unsatisfied, recursion thus end) -> f_3 -> f_2 -> f_1

        Note that the code isn't copied in a recursion, which is much like a loop.


        e.g 2:
        e.g.2 prints out the binary form of a positive integer.

    2/ Pros and cons of recursion
        Compared with loop,
            pros: easier to code, and the code is more elegant
            cons: can easily exhaust computer memory
                  harder to document and maintain
                  harder to do input validation (?)

        Take e.g. 3 as an example,
            Recursion offer a compact solution, of course. But when computing #100 Fibonacci number, too slow.




*/
void up_and_down(int n)
{
    printf("Level %d, location: %p\n",n,&n);    // %p: address
    // Here, n is the formal argument for Level i up_and_down( )
    if (n < 4){
        up_and_down(n + 1);
        // Here, n is an actual argument for Level i+1 up_and_down( )
        // The n in level 1 is different from the n in level 2
        //      t/f their address are different.
    }
    printf("Level %d, location: %p\n",n,&n);

}

void to_binary(int n)
{
    int r = n % 2;
    if (n != 0){
        n = (n - r) / 2;
        to_binary(n);
    putchar((r == 0) ? '0' : '1');
    // Note how the reverse order of execution match the order of binary representation
    }
}

unsigned long fibonacci(unsigned long n)
{
    if (n > 2){
        return fibonacci(n-1) + fibonacci(n-2);
    }
    else{
        return 1;
    }
}




int main(void)
{
    // e.g. 1
   // up_and_down(1);

    //e.g. 2
    int m = 23;
 //   to_binary(m);
    putchar('\n');

    //e.g. 3
    int n;
    printf("Enter a number n, I will compute the #n Fibonacci number (q to quit)");

    printf("\nMethod 1: Recursion\n");      // O(2^n)  b/c double recursion, each level follows two levels
    while (scanf("%d",&n) == 1){
        printf("The #%d Fibonacci number is %d.\n\n", n, fibonacci(n));
        }

    fflush(stdin);
    putchar('\n');

    printf("\nMethod 2: Loop\n");           // O(n)
    long a, b, fibn;
    while (scanf("%d",&n) == 1){
        a = 1; b = 1;
        if (n == 1 || n == 2){
            fibn = 1;
        }
        else if (n > 2){
            n -= 1;
            while (n > 1){
                n -= 2;
                a = a + b;
                b = a + b;
            }
            fibn = ((n + 1) % 2 == 0) ? b : a;
        }
        else {
            printf("Invalid input. Please enter a positive integer.\n\n");
            continue;
        }


        printf("The #%d Fibonacci number is %d.\n\n", n, fibn);
    }






    return 0;
}
