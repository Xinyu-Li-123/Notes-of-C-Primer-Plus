
/* This .c file covers basic knowledge of expression & statement and function with arguments
        and a little knowledge of looping. */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// C has a built-in math library
#define PI 3.141593
// PI is a symbolic constant (preprocessor-defined)


void num2hash(int num);     // see Part 6

int main(void)
{

/* Part 1. Loop */

    const double h = 6.626;
// h is another kind of symbolic constant
// CONSTANTs are read-only !!   (they are stored somewhere else, a place where you can't access)
    printf("pi is about %f\n",PI);
    printf("Planck constant is about %.3fe-34\n",h);
    int i = 1; int j = 0; int r = 1;
    // the while loop
    while (++j < 6)         // recap: while (1) ==> infinite loop;  while (0) ==> do nothing (0,1 are boolean data type, 0 is false, i is true)
    // while (test condition)
    // the code above is a shorthand for while (j<6){++j; following command;}
    // rmk. Written in this way, ++j is always the FIRST to be executed
    // order: if ++j, j = j + 1 ==> j < 6 ?   ==> {remaining commands}
    //        if j++, j < 6 ?   ==> j = j + 1 ==> {remaining commands}

        printf("%d*pi = %f\t\t",j,j*PI);
        printf("\nThe while loop is done\n");
        // Without the braces , while will only run statements till the next semicolon.

    printf("\n");

    // the for loop
    for (i; r<6 && !(i>3); i++)    // &&: and, ||: or, !: not
    // for (initial value; test condition; changes after each iteration){}
    // rmk: the "change" is always the LAST to be executed
    {
        printf("%d*pi = %f\t\t",i,i*PI);
        r++;
    }
    printf("\n\nThe for loop is done\n");
    printf("\n%f\n",pow(2.2,3.3));

/* Part 2. Assignment Statement
Terminology:
    object: (diff from OOP's object) refer to an actual data storage

    lvalue: left / object-locater value, a label used to identify / locate the data storage
            rmk. only modifiable lvalue can stay at the left side of an assignment statement

    rvalue: right value, not lvalue

    operand: an item that operators operate on
*/


/*Part 3. Some Special Operators and Operator Precedence*/
// 1. /: Division operator, if int / int, return int; if float / float, return float

// 2 sizeof: unitary operator, return the size of the operand in Byte.
//   size_t: In fact, sizeof return a value of type size_t.
//        size_t is an unsigned integer. It is defined as "typedef unsigned int size_t"
    printf("It takes %d Bytes to store the constant PI.\n",sizeof PI);
    printf("It takes %d Bytes to store the number i.\n",sizeof i);
//              typedef a b := define a new data type b based on a (i.e. b is just another name of data type a)

// 3. %: Modulus Operator
    float a = 5.0/4.0;
    printf("%d / %d = %d ...... %d\n",43, 12, 43/12, 43%12);
    printf("a ~= %.0f\n",a);
    printf("a ~= %.1f\n",a);
// C truncation method: round() (not (floor() or ceil()))

// 4. ++ and --: add / subtract by 1
// rmk. a++ (postfix) is different from ++a (prefix)
//  a++: first a     , then a += 1
//  ++a: first a += 1, then a
    int aa = 1; int bb = 1;
    int aa_post, pre_bb;
    aa_post = aa++; // value of aa++ during assignment phase: aa_post = aa; aa = aa + 1
    pre_bb = ++bb; // value of ++bb during assignment phase : bb = bb + 1 ; pre_bb = bb
    printf("aa aa_post bb pre_bb \n");
    printf("%1d %5d %5d %5d\n", aa, aa_post, bb, pre_bb);


// Extra: Operator Precedence
// = to be continued =>



/* Part 3. Expression and Statement
0. The Golden Rule
    program step = {statement}, statement = {expression}.
1. Expression
    Expression is a combination of operators and operands
    Every expression has a value !
      expression              value
         4                      4
       5 + 3                    8
     c = 2 + 1                  3
    6 + (c = 2 + 1)             9 (legal, but not recommended)

2. Statement
    Statement = combination of expressions + ;
        me = 8  // expression
        me = 8; // statement
    Statements are the primary building blocks of a program.
    A program is a series of statements with some necessary punctuation.
    A statement is a complete instruction to the computer.

    Types of statement:
        Declaration   statement: int a;
        Assignment    statement: a = 1;
        Function call statement: printf("a = %d",a)
        Structured    statement: while(a<10){print("a = %d",a); a += a;}
        Return        statement: return a
        Null          statement: ; // the simplist statement in C

3. More terminology
    1/ side effect
    A side effect is the modification of a data object or file.
    e.g.
        1// "number = 10" has the side effect of assigning 10 to number.
        This is named this way b/c for C, the main intent is to evaluate expression
            (in this case, evaluate the expression "number = 10" to 10)
        2// ""printf("Hello world!\n") has the side effect of printing something out,
            the value of printf() is #items it display
                (e.g. the value of "printf("123456\n%d",2) is 8 (7 items)")

    2/ sequence point
    A sequence point is a point in program execution at which all side effects are evaluated before
    going on to the next step.
    In C, the semicolon in a statement marks a sequence point.
          some operators also have sequence points
          the end of any full expression is a sequence point.
                (full expression: an expression that is not a subexpression of any other expression
                 e.g. 1// a = 6 + (c = 1 + 4);   // "a = 6 + (c = 1 + 4)" is a full expression,
                                                 // "c = 1 + 4" is a subexpression, not a full expression
                      2// the expression serving as a test condition for a while loop.
    C only guarantee that all expressions will be evaluated at the sequence point
    e.g. "(4 + x++) + (6 + x++);" is a full statement. ; marks the sequence point of the stateemnt
        C can only guarantee that when reach ;, x will be incremented twice,
            but can't guarantee when will x be incremented inside the full statement,
            which is why you should avoid such confusing statement

    3/ Compound Statements (Blocks)
    A compound statement (block) is two or more statements grouped together by enclosing them in braces.
    e.g. "while(x){y; z; r;}" will run the block right behind it if the test condition is true.
*/


/* Part 4. Type Conversions
    Normally, statements and expressions should deal with variables of the same data type.
    If not, C will automatically do type conversion. This is both convenient and dangerous, for it can give you incorrect output.
    Therefore, you should have some knowledge of type conversions

    The basic rules are:
    1/ Promotion
    Conversion from small data type to large data type
        1// Promotion in an expression
            signed / unsigned  char / short ==> (unsigned) int  (char is stored as an ASCII code, which is an integer)
        2// Promotion in a binary operation
            Always convert to the higher ranking types of the two types
        3// Ranking of Data Types
            (from highest to lowest)
          |  long double
          |  double
          |  float
          |  unsigned long long
          |  long long
          |  unsigned long
          |  long
          |  unsigned int
          V  int
                    (short, char ==> int)

        4// Type Conversion in Assignment Statement
        In an assignment statement, the final result of the calculations
        is converted to the type of the variable being assigned a value

        e.g.
        float a;
        a = 1 + 2;  // The result of "1 + 2" is converted to a float 3 b/c a is float

        This can cause either promotion or demotion.

        5// Type Conversion in Function Arguments
        When passed as function arguments,
        short, char ==> int
        float       ==> double

        This can be overridden by function prototyping

    What will happen if the converted type can't fit into the destination?
        1// ???? (well, I don't know)
 */


/* Part 5. Cast Operators
    Cast Operators allow programmers to convert the data type manually.

    (type) is a typical type operator. */
    int t;
    t = 2.6 + 3.7;
    printf("\nt = %d\n",t);     // t = 6
    // (2.6 + 3.7) return 6.3 ==> truncate 6.3, toward 0, to 6 b/c t is int ==> t = 6
    t = (int) 2.6 + (int) 3.7;
    printf("\nt = %d\n",t);     // t = 5
    // (int) 2.6 return 2, (int) 3.7 return 3 ==> (2 + 3) return 5 ==> t = 5


/* Part 6. Functions with arguments
Terminology:

    In the program:
    void num2hash(int num)
    {
        while(num-- > 0)
            printf("#");
        printf("\n");
    }
    int times = 12;
    num2hash(times);

num2hash(): function
void      : data type of the returned value (here, no return, t/f void)
num       : formal argument (parameter)
times     : actual argument (argument)
            (More precisely, the value of times (12) is the actual argument)

the function call passes the value of times (actual arg)to num (formal arg)
*/

    int times;
    printf("How many # do you want me to print: ");
    scanf("%d",&times);
    num2hash(times);

    num2hash('R');      // type conversion: char ==> int (ASCII)
    num2hash(21.3345);  // type conversion: float ==> int (truncate towards 0)

    return 0;
}


void num2hash(int num)
{
    while (num-- > 0)
        printf("#");
    printf("\n\n");
// parameter's name is private. i.e., it won't conflict with the same name outside this function
}


