#include <stdio.h>
#include <complex.h>


int change_answer(char *answer)
{
    char temp[5];
// since there is a null character '/0' at the end of temp,
// char temp[5] can store at most 4 characters, therefore we use 5 instead of 4 here.
    int i=0;
    for(i=0;i<4;++i)
//  for(initial i; when won't i stop; update i)
    {
        temp[i] = answer[i];
    }
    printf("temp is %s\n",temp);
    answer[0] = temp[3];
    answer[3] = temp[0];
    return 0;
}

int ascii2char(int i)
{
    char chari = i;
    printf("ASCII code value %d represents %c",i,chari);
    return 0;
}

int main(void)
{
/* Q0 */
    char answer[]="ACBD"; // The answer (ABCD) of a piece of reading comprehension
    printf("The original answer is %s\n",answer);
    change_answer(answer);
    printf("The alternated answer is %s\n",answer);
    int i;
    printf("Please enter the number of the question: ");
    scanf("%d",&i);
    printf("The answer for Q%d is %c\n",i,answer[i-1]);
    printf("which is stored in memory at location: %d\n",answer+i-1);

/* Q1 */
    int ascii;
    printf("Please enter an ASCII code value: ");
    scanf("%d",&ascii);
    ascii2char(ascii);

/* Q2 */
    printf("\a");
    printf("\nStartled by the sudden sound, Sally shouted,\n\"By the Great Pumpkin, what was that!\"\n");
    return 0;
}
