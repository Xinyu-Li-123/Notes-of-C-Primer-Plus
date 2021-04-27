# include <stdio.h>
# include <stdlib.h>

int main(void)
{
     float weight; /* user weight */
     float value; /* platinum equivalent */
     printf("How much do you worth your weight in platinum?\n");
     printf("Let's check it out.\n");
     printf("Please enter your weight in pounds: ");
     /* get input from the user */
     scanf("%f", &weight);
/* scanf() ask C to read keyboard input.
   More specifically, scanf("specifier",&var_name) ask C to store keyboard input into var_name
        as a data type indicated by specifier.
   With scanf(), the program becomes interactive !! */
     value = 1700.0 * weight * 14.5833;
     printf("Your weight in platinum is worth $%.2f.\n", value);
/* %f is the specifier for floating numbers, .2 means represent 2 digits of decimal*/
     printf("You are easily worth that! If platinum prices drop,\n");
     printf("eat more to maintain your value.\n");
    return 0;
}
