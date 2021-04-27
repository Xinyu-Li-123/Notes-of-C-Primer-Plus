#include <stdio.h>
#include <ctype.h>
/* ctype.h
    ctype.h header file contains some standard functions for analyzing characters
        These functions take a character as an argument and return nonzero (true)
        if the character belongs to a particular category and zero (false) otherwise.

    Char-testing Functions:
        isalpha() :  is input alphabetic?
        isalnum() :  is input alphabetic or numeric?
        isblank() :  A standard blank character (space, horizontal tab, or newline) or any additional
                        locale-specific character so specified
        iscntrl() :  A control character, such as Ctrl+B
        isdigit() :  A digit
        isgraph() :  Any printing character other than a space
        islower() :  A lowercase character
        isprint() :  A printing character
        ispunct() :  A punctuation character (any printing character other than a space or an alpha-numeric character)
        isspace() :  A whitespace character (a space, newline, formfeed, carriage return, vertical
                        tab, horizontal tab, or, possibly, other locale-defined character)
        isupper() :  An uppercase character
        isxdigit():  A hexadecimal-digit character

    Char-mapping Functions:
        tolower(): upper => lower, others remain
        toupper(): lower => upper, others remain
*/
#include <iso646.h>
/*
iso646.h provides an alternative for logical operators
&& ==> and
|| ==> or
!  ==> not
*/

#define MAX 100.0f
#define MIN 0.0f


int main(void)
{
/* getchar() and putchar()
    These are char specific functions built in stdio.h. They are faster b/c they only deal with characters
    ch = getchar();  <==>  scanf("%c",&ch);
    putchar(ch);     <==>  printf("%c",ch);

*/

    char ch;
    printf("please enter a sentence: ");
    while ((ch = getchar()) !='\n'){
        // C evaluate "ch = getchar()" as the input character.
        if (isalpha(ch))
        // <==>  if(ch >= 65 && ch <= 122)
            putchar(ch + 1);
        else
            putchar(ch);
    }

    fflush(stdin);


// nested if: find all divisors of an integer
    int num,i,j,isprime;
    printf("\n\nPlease enter an integer(enter q to quit): ");
    while(scanf("%d",&num) == 1){
        for(i = 2, j = 0, isprime = 0; i < num; i++){
            if (num % i == 0){
                isprime++;
                if(isprime == 1){
                    printf("Divisor(s) of %d: ",num);
                    isprime++;
                }
                printf("%d ",i);
                j++;
            }

        }
        if (j == 0){
            printf("%d is a prime number",num);
        }
        printf("\n\nPlease enter an integer(enter q to quit): ");

    }

/* Precedence of logical operators
&&, || are sequential points, i.e., all side affects take place from left to right
*/

    fflush(stdin);

    int charc, wordc, linec;
    charc = (wordc = (linec = 0));
    printf("\nplease enter some text (enter | to terminate): \n");
    while ((ch = getchar()) != '|'){
        if (ch == ' '){
            wordc++;
        }
        else if (ch == '\n'){
            linec++;
            wordc++;
        }
        else if (isalpha(ch)){
            charc++;
        }
    }
    wordc++;
    linec++;

    printf("\nIn this piece of text:\ncharacters: %d\nwords: %d\nlines: %d\n", charc, wordc, linec);

/* Part 2. Conditional Operators ? :
    This operation takes three operands (ternary)
    ((test) ? (if statement) : (else statement) ;

    e.g.1
    x = ((y < 0) ? -y: y);      // the outer () is redundant b/c C evaluate an equation from right to left, and (xx)?xx:xx is one single ternary expression
    <==>
    if (y < 0)
        x = -y;
    else
        x = y;

    e.g.2 (a typical one)
    max = (a > b) ? a : b;

    ? : operators can greatly simplify our code
*/


    fflush(stdin);

    const int cov = 350;
    int area;
    int cans;
    printf("Enter the area to be painted in square feet (enter q to quit): ");
    while(scanf("%d",&area) == 1){
        cans = area / cov;
        cans += (area % cov) ? 1 : 0;
        printf("You need %d %s of paint.\n",cans,(cans <= 1) ? "can" : "cans");
        printf("Enter the area to be painted in square feet (enter q to quit): ");
    }
    // prop of demotion:
    //      int i; i = 1.1; ==> i = 1
    //      int j; j = 1.8; ==> j = 1 (ceil(j)

    fflush(stdin);


/* Part 3. Loop Aids: continue and break
    continue: skip the rest of the loop, enter next iteration
                continue can make the program more readable

                When continue:
                    in while loop, C will then evaluate the test condition
                    in for loop, c will then evaluate the update statement

    break: leave the loop, execute next statement outside the loop
*/

    float min = MAX;    // so that the first assignment assign score to min
    float max = MIN;    // same
    float score, total = 0;
    int m, n;
    printf("Enter the first score (0.0~100.0, q to quit): ");
    for (n = 0; scanf("%f",&score) == 1; printf("Enter next score (0.0~100.0, q to quit): ")){
        if (score < MIN || score > MAX){
            printf("Invalid input!\n");
            continue;       // Use continue to skip the invalid input & rest of the loop, and enter the next iteration
        }
        n++;
        total += score;
        min = (score < min) ? score : min;
        max = (score > max) ? score : max;
    }
    if (n > 0){
        printf("-------------------\nSTATISTICS:\nTotal score: %f\nAverage: %f\nLowest: %f\nHighest:: %f\n "
               ,total, total/n, min, max);
    }
    else printf("There is no valid input!");


    fflush(stdin);


    for (n = 1, m = 1; n < 15; n++){
        if (m % n == 3)
        break;
        for (; m < 8; m++){
            if (m % n == 3)         // x mod 0 is invalid
                break;              // use break to leave the layer of loop where break locates
        }

    }
    printf("m = %d\nn = %d\nm mod n = %d\n",m, n, m%n);     // after break, update statement won't be evaluated


/* Part 4. Multiple Choice: switch and break

    switch (var)
    {
        case con1:
            printf("var == con1 is true");
            break;              // leave the switch block. Without break, C will evaluate the next case
        case ccn2:
            printf("var == con2 is true");
            break;              // without break, C will evaluate from the match case to the end of the switch block
        case con3:
            printf("var == con3 is true");
            break;
        default:                // optional, without a default, C will jump to whatever follow the switch block
            printf("var not in {var1, var2, var3}");
    }

    Switch expression (var) must be integer expression (return integer, including char)
    Case expression (con1, called label) must be integer constant. Variables (even int) can't be label

    Switch is more restricted, while a bit faster to execute and more compact than if-else

*/

    // Funny Word Generator
    printf("\n-------------------\n|| Funny Word Generator ||\n\n");
    printf("This machine will generate a funny word that start and end with the same letter you enter. \n\nEnter a letter (enter # alone to quit): ");


    while ((ch = getchar()) != '#')
    {
        while (ch == '\n'){      // omit the [enter] between each line
            ch = getchar();
            continue;
        }

        if (isalpha(ch)){
            switch (ch)             // print a funny word
            {
                case 'a':           // this allows multiple labels
                case 'A': printf("acatamathesia: inability to understand data presented to the senses\n\n"); break;
                case 'b':
                case 'B': printf("bafflegab: incomprehensible or pretentious verbiage, especially bureaucratic jargon\n\n"); break;
                case 'c':
                case 'C': printf("cheiloproclitic: attracted to lips\n\n"); break;
                case 'd':
                case 'D': printf("dendroid: tree-like; resembling a tree\n\n"); break;
                case 'e':
                case 'E': printf("endoscope: instrument for visualizing interior of a hollow organ\n\n"); break;
                case 'f':
                case 'F': printf("flagstaff: flag pole at stern of a ship\n\n");break;
                default: printf("That's a stumper!\n\n");
            }
        }
        else
            printf("That is not a letter!\n\n");

        while (getchar() != '\n')   // this is a common technique to take only the first input and omit the rest
            continue;

        printf("Enter the next letter: ");
    }


/* Part 5. The goto Statement
    Well, just don't use it. You really don't need goto in C.
*/





    return 0;
}
