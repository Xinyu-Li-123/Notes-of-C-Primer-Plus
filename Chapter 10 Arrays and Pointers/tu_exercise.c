#include <stdio.h>
#include <stdlib.h>


int * fruitshop(void)
{
    static int sale[5]={23,9,12,45,34};

    return sale;
}

int * doublesale(int*sale)
{
    int*dsale = sale;
    int i=0;
    for (i = 0; i < 5; ++i)
    {
        dsale[i] = 2*sale[i];
    }
    return dsale;
}
void main(void)
{
    int *s=fruitshop();
    int i = 0;
    for (i = 0; i < 5; ++i)
    {
        printf("%d apples are sold on day %d\n",*(s+i),i+1);
    }
    printf("if doubled, it will be like:\n");
    int*ds = doublesale(s);
    for (i = 0; i < 5; ++i)
    {
        printf("%d apples are sold on day %d\n",*(ds+i),i+1);
    }
}
