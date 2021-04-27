
/* This .c file covers the basic knowledge of loop (while, for, do while)*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159
/* Part 0. Prologue

What does a program do (3 forms of program flow)
  1/ Executing a sequence of statements
  2/ Repeating a sequence of statements until some condition is met (looping)
  3/ Using a test to decide between alternative sequences (branching)

*/

//-------------------------------------------------------------------------------------------------------------------

void sum_num(void);
void guess_pi(void);
void print_funny_str(void);
void translate_word(void);
double power(double n,int p);     // return n^p

int main(void)
{


/* Part 1. The while loop
while is an entry-condition loop
    the condition must be met before each iteration the loop.
    It's possible that the statements are never executed

while (expression){
    statement
}

expression is true  <==> expression returns nonzero (e.g. 3, 3.1415, 'm')
expression is false <==> expression returns zero (e.g. 0,'')

"2 == 2" return 1 (nonzero for true), "2 == 1" return 0 (zero for false).
*/

sum_num();

while (0)
    ;   // this is the simplist form of while loop, i.e., loop a null statement
        // this is particularly useful when all the work gets done in the test.


//-------------------------------------------------------------------------------------------------------------------
/* Part 2. Relational Operators
>  >=  <  <=  ==  !=
can be used it to compare number, char
can't be used on string
if used on float, avoid ==, != b/c of rounding error.
*/

char myChar = 'A';
while (++myChar <= 'z' )
    printf("%c  ",myChar);

fflush(stdin);          // scanf: if input doesn't match, scanf will leave the input in the buffer,
                        //      when call scanf() again, scanf will first read whatever inside the buffer.
                        //      this could once again caused a match-error
                        //  To deal with it, use "fflush(stdin)" to flush the output buffer after a failed scanf()
guess_pi();

/* Precedence of relational operators

 |   ()
 |   ++  ¨C¨C  sizeof + - (take positive / negative, unary)
 |   *  /  %
 |   +  -
 |   <  >  <=  >=
 |   ==  !=
 V   =

*/


//-------------------------------------------------------------------------------------------------------------------
/* Part 3. The for loop
for is also an entry-condition loop

for (initialize; test; update){
    statement
    statement
}

Valid e.g.
1/ for (i = 1; i < 10; i++)
2/ for (j; j < 20; j++)
3/ for (j = 1; j<20; )j++;
4/ for (j = 1; err < 0.0001; j += 2)
5/ for ( ; ; ) // an infinite loop if no break inside

NOTE: You can't omit the semicolon !!
*/

int count;

for (count=1; count<=5; count++){
    printf("This is the #%d iteration\n",count);
}
 /* for loop analogy

 count = 1;     initialize  |
 count <= 5?    test        |
 printf(...)    statements  |
 count++        update      |
 count <= 5?    test        |
 ...            ...         V

 */


for (count = 'A'; count <= 'z'; count++){
    printf("The ASCII code for %c is %d\n",count,count);
}

// The comma operator
//  comma allows to deal with multiple initialize / test / update in the for loop (though it's not specific to for loop)
//  rmk: 1/ "exp1, exp2, exp3;" is evaluated in a left-to-right order !!
//              i.e. (jargon) the comma is a sequence point, the left side effect takes place before the right side effect
//              e.g.  "x = (y = 3, (z = ++y + 2) + 5);"  this statement returns 11 (side effect: x = 11)
//       2/ comma can also be used as a separator
//              e.g. int a, b;
int price, delta;
for (count = 1, price = 0, delta = 10; count <= 10 && price + delta <= 100; count++, price += delta, delta++ ){
    ;   // the for() has pretty much done everything needed, so "nullthing" need to be done inside {}  :)
}
printf("\nThe price is $%d\n\n",price);  // b/c of the test condition, the final price is sum(10,17,1) = 108


// Zeno's Paradox

double pow,sum2;
for (pow = 1.0, sum2 = 0; 2 - sum2 > 0.000001; sum2 += 1/pow, pow *= 2){
    printf("sum = %lf,  err = %lf\n",sum2, 2 - sum2);
}
printf("\n");


//-------------------------------------------------------------------------------------------------------------------
/* Part 4. The do while loop
do while loop is an exit-condition loop,
    the condition is examined after each iteration
    the statements will be executed at least once

do
{
    statements
}
while (condition)

*/

count = 0;
do{
    printf("Greeting!\n");
    count++;
}
while (count < 6);    // iterate for 6 times


//-------------------------------------------------------------------------------------------------------------------
/* Part 5. Which Loop should I use?

1/ entry-conditioned or exit-conditioned ?
    Usually, entry is a better choice, b/c
        1// It is better to look before you leap (or loop) than after
        2// A program is easier to read if the loop test is found at the beginning of the loop
        3// In many uses, it is important that the loop be skipped entirely if the test is not initially met.

2/ for or while?
    A matter of taste (I prefer for)

*/


//-------------------------------------------------------------------------------------------------------------------
/* Part 6. Nested Loop & Array

1/ Array
    An array is a series of values of the same type stored sequentially
    e.g. 1/ float debt[5] = [1.1, 2.5, 4.442, 5.6, 99];
         2/ debt[2] = 10.4;             // 3rd elements of debt = 2 (C counting starts from 0, not 1)
         3/ scanf("lf", &debt[1])       // store input into the second element of float array debt
         4/ char myStr[5] = "Eiger";    // string is a special kind of char array with "\0" in the end

    rmk: C doesn't check if "debt[10] = 2" really has 11 elements, so it's a potential hazard

2/ String
    String is a special kind of char array. It ends with a null char "\0", which indicates where the string ends.
    The numbers identify elements are called subscripts / indices / offsets
    subscripts starts from 0, must be integer
*/

print_funny_str();

fflush(stdin);

translate_word();

/* Extra: pow function*/

double n = 2.33;
int p = 6;
printf("\n\n%lf^%d = %lf\n\n",n,p,power(n,p));

return 0;
}





// Write your program in a modular way, for the convenience of understanding and modification


void sum_num(void)
{
    double num;
    double sum = 0;

    printf("please enter a number (enter q to quit): ");
    while (scanf("%lf",&num) == 1)     // i.e. while input is double
    // Recap: scanf() return #correctly scanned number
    //  (%d: enter an integer ==> return 1, enter a double ==> return 0)
// this while statement is equiv to "status = scanf(...); while (status == 1) {scanf(...)}"
    {
        sum += num;
        printf("please enter a number (enter q to quit): ");
    }
    printf("\nThe sum of the numbers you entered is: %lf\n\n",sum);
}


void guess_pi(void)
{
    double ans;
    printf("\n\nWhat is the value of pi: ");
    scanf("%lf",&ans);
    while (fabs(ans - PI) > 0.1)     // fabs(num) == float absolute value of a float number
    {
        printf("try again: ");
        scanf("%lf",&ans);
    }
    printf("Close enough.\n");
}




void print_funny_str(void)
{
    const int ROW = 5;
    const int COL = 9;
    int i,j;
    for (i = 1; i <= ROW; i++){
        printf("\n");
        if (i <= COL){
            for (j = 1; j <= i; j++){
                printf("%c",'A'-1+j);
            }
        }
        else{
            for (j = 1; j <= COL; j++){
                printf("%c",'A'-1+j);
            }
        }

    }
    printf("\n\n");
}


void translate_word(void)
{
    char word[4];
    int k;
    printf("Type in a 4-letter word: ",k+1);
    for (k = 0; k < 4; k++){
        scanf("%c",&word[k]);
        // since all input of scanf are stored in the buffer, you can type in all letters,then press enter
    }

    printf("\nThe translated word is: ");
    for (k = 0; k < 4; k++){
        printf("%c",word[k]+k);
    }

}


double power(double n,int p)
{
    int count;
    double ans;
    for (count = 0, ans = 1; count < p; ans *= n, count++);
    return ans;
}
