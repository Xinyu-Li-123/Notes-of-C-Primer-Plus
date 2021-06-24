/* This .c file is a random number generator that utilizes different storage classes
    It can be useful in a D&D or CoC game.
*/

#include<stdio.h>
#include<time.h>

/*
    How to generate a random number?
        Although C does have a rand() function that can generate random number, we are gonna
            create a portable algorithm that are independent from different OSs.
        The algorithm is called linear congruence method. It can generate
            pseudo-random numbers (seemingly random, but periodic)
        It do linear transform on the last num and take its module to get the next num.
            x_n+1 = (a*x_n + c) mod m
        To reach the maximal period (which is m),
        -   m and c should be coprime
        -   prime factors of m should devide a-1
        -   a, c, x_0 < m
        -   a, c should be positive integers

        We will start with a number called "seed", then iterate it to generate a new number,
            which will become the new seed, and so on. Thus, the random number generator must
            remember the last seed, which calls for a static variable.
*/

static unsigned long int next = 1; // the first seed

int rand0(int inf, int sup)
{
    int gap = sup - inf + 1;
    next = (next * 1103515245 + 12345);
    return (unsigned int) (next/65536) % gap + inf;
    // a random integer in [0, sup] with a maximal period of
}

int main(void)
{
/*
    time() is a function in time.h. It takes in the address  (i.e. the pointer) of a time_t variable,
        and returns an integer (??) which is dependent of the system time
    If the input is a null pointer (i.e. time(0)), another mechanism applies.

    Using time(), we can initialize the seed with our system time
*/

    int times, per_time, inf, sup;
    int rnum, sum;
    printf("============== Roll 'em ==============\n");
    printf("inf: "); scanf("%d", &inf);
    printf("sup: "); scanf("%d", &sup);
    printf("times: "); scanf("%d", &times);
    printf("roll per time: ", &per_time); scanf("%d", &per_time);
    puts("");

    for(int count = 0; count < per_time; count++)
        printf("#%d  ", count+1);
    printf("   sum\n");

    next = time(0);
    for(int count = 0; count < times; count++){
        sum = 0;
        for(int count = 0; count < per_time; count++){
            rnum = rand0(inf, sup);
            sum += rnum;
            if (rnum < 10)
                printf("%d   ", rnum);
            else if (rnum < 100)
                printf("%d  ", rnum);
            else
                printf("%d ", rnum);
        }
        printf("   %d\n", sum);
    }
    return 0;
}
