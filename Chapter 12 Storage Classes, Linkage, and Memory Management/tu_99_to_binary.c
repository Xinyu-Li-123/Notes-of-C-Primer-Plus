#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "const.h"

#define word_0 "This is a sentence."
#define WORDCOUNT 5
#define WORDSIZE 40


int fibonacci_num(int n)
{
    int a,b,i,m;
    m = (n%2) ? (n+1)/2 : n/2;
    for (a = b = 1, i = 1; i < m; i++){
        a = a + b;
        b = a + b;
    }
    return (((n%2) ? a : b));
}

char *s_gets(char *input_str, int n) // see tu_02_string_input.c
{
    int i = 0;
    char *ret_val;
    ret_val = fgets(input_str,n + 1,stdin);
    if (ret_val){
        while (input_str[i] != '\n' && input_str[i] != '\0')
            i++;
        if (input_str[i] == '\n')
            input_str[i] = '\0';
        else{
            while (getchar() != '\n')\
                continue;
        }
    }
    return ret_val;
}

static int * bn;
static int count = 0;
static int pflag;   // positive flag: (n > 0) ? 1 : 0;

void to_binary(int n)
{
    if(n != 0 || count != 0){
        int m = (n >= 0) ? n : -n;
        int r = m % 2;

        if(count == 0){
            pflag = (n > 0) ? 1 : 0;
        }

        int i = count++;
        if(m != 0)
            to_binary((m-r)/2);
        else
            bn = (int *) calloc(count, sizeof(int));

        bn[count - 1 - i] = r;

        if(!pflag && i == 0){
            int j = count;
            bn[0] = 1;
            for(; j > 0; j--){
                if(bn[j] == 0)
                    continue;
                else if(bn[j] == 1){
                    j--;
                    break;
                }
            }
            for(; j > 0; j--)
                bn[j] = (bn[j]+1) % 2;
        }
    }
    else if(n == 0){
        count = 1;
        *bn = 0;
        printf("%d", *bn);
    }
}

int main(void){

    int n;
    while(scanf("%d", &n)){
        to_binary(n);
        for(int i = 0; i < count; i++){
            printf("%d", bn[i]);
        }
        putchar('\n');
        free(bn);
    }






    return 0;
}




