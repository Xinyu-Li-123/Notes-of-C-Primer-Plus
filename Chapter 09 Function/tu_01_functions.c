/* This .c file covers basic knowledge of function in C */

#include <stdio.h>
#include <string.h>

/* Part i. Recap on function
    C's design philosophy is to use functions as building blocks

    function: a self-contained unit of program code designed to accomplish a particular task

    Using function allows modular design of your program.
        You can first think of what each module should do and write your code formally (without specific contents)
        Then fill in those modules

    In th declaration/prototype statement of a function,
        we will define what's the type of arguments & return value.
        Collectively, we call this information the signature of the function.

    One could save the main() and a specific function in different files,  but we will leave that to later chapter.


*/


#define NAME "GROUNDWORK.inc"
#define ADDRESS "602 METROPOLIS"
#define EMAIL "DontEmailMe@fakemail.com"




void put_multi_char(char ch, int count)
{
    while (count--){
        putchar(ch);
    }
}

int indent_print(char *str, int count)     // to print the string in the middle
{
    if (strlen(str)%2 == 0){
        put_multi_char(' ', (count - strlen(str))/2);
        printf("%s\n",str);
        return 1;
    }
    else if (strlen(str)%2 == 1){
        put_multi_char(' ', (count - strlen(str)-1)/2);
        printf("%s\n",str);
        return 1;
    }
    else
        return 0;

}

int imin(int a, int b)
{
    return (a < b) ? a : b;            // type demotion: double --> int
    // if type(returned value) != type(returned value defined in prototype),
    //      then do conversion (promotion / demotion)

}




void main(void)
{

    // This program print the information of a company in the format of a letter.
    const int COUNT = 40;
    put_multi_char('*', COUNT);
    printf("\n");
    int ccount = 0;
    ccount += indent_print(NAME, COUNT);
    ccount += indent_print(ADDRESS, COUNT);
    ccount += indent_print(EMAIL, COUNT);
    printf("\n");
    put_multi_char('*', COUNT);
    printf("\n\n%d out of %d items are correctly printed out.\n\n", 3, ccount);




/* Part 2. return*/

    double a = 20.923;
    double b = 30.832;
    int lesser = -99999;
        char flag;
    if (((int) a != a) || ((int) b != b)){      // input validation: (a not double ) or (b not double)
        printf("Your input of min(a, b) are not integers\nDo you want me to ceil the input? (y to ceil, n to quit)");

        flag = getchar();
        fflush(stdin);

        if (flag == 'y'){
            lesser = imin((int) a, (int) b);                        // ceil a and b by type conversion
            printf("\nmin(%d,%d) = %d\n",(int) a,(int) b,lesser);
        }
        else{
            ;
        }
    }
    else{
        lesser = imin(a, b);
        printf("\nmin(%d,%d) = %d\n",a,b,lesser);
    }




}
