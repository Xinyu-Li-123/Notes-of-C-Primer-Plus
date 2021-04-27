#include <stdio.h>

int main(void)
{
    char first[10];
    char last[10];
    int num,status,t;
    int sum = 0;
    printf("Please enter your first name+last name: ");
    scanf("%s %s",&first,&last);
    // scan 2 strings at 1 time
    printf("Hello, %s %s."
           "Nice to meet you!\n",first,last);
    printf("Wanna enter a number? (enter q to quit): ");
    status = scanf("%d",&num);
    // The return value is #correctly stored stuff
    // e.g. count = scanf("%d %d %d",&a, &b, &c)
    //  if enter: 1,2,xix, then count == 2
    while(status == 1)
    {
        sum = sum + num;
        printf("Wanna enter a number? (enter q to quit): ");
        status = scanf("%d",&num);
    }
    printf("The sum of the numbers your enter is %d\n", sum);

    t = 0;
    while(++t<4);
    //1.  ++t<4 means:
    //      t<4?
    //          Y --> ++t (t = t + 1)
    //          N --> break
    //2. if add ; right behind while, then while only run code inside ()
    printf("t = %d\n",t);
    return 0;
}
