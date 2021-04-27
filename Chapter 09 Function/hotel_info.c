/* This .c file is a function support file. It define the function prototype in hotel_info.h */

#include <stdio.h>
#include "hotel_info.h"     // include the header file




int menu(void)
{
    int choice = 0;
    int status = 0;
    printf("%s%s\n",STAR, STAR);

    printf("Please enter a number in 1~5\n");
    while (status != 1){

        printf("Which hotel do you prefer?\n");
        printf("1) Hotel California         2) Home Sweet Home\n");
        printf("3) Longhamm hotel           4) The Hotel at the End of the Universe\n");
        printf("5) None\n");

        if ((status = scanf("%d",&choice)) == 1)
            break;

        printf("You must enter a number between 1 and 5!\n");
        while (getchar() != '\n')   // clear the left input in stdin
            continue;
    }
    return choice;
}


int get_night(void)
{
return 111;
}


double show_price(double rate, int nights)
{
return 233;
}
