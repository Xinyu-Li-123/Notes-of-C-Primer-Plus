#include <stdio.h>



char* a2z(void)
{
    static char alphabet[26];
    int i;
    char ch = 'a';
    for (i = 0; i < 26; i++, ch++){
        alphabet[i] = ch;
    }


    return alphabet;
}


double calculate(double num_a, double num_b)
{
    double ans;
    if (num_a*num_b == 0){
        printf("Neither a or b can be zero.\n");
        ans = -999;
        }
    else{
        ans = (num_a - num_b) / (num_a * num_b);
    }
    return ans;
}

int main(void)
{
//1

    char* alphabet = a2z();
    int i,j;
    for (i = 0; i < 26; i++){
        printf("%c ",alphabet[i]);
    }
    printf("\n");


//2
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    fflush(stdin);
    for (i = 1; i <= num; i++){
        for(j = 1; j <= i; j++){
            printf("$");
        }
        printf("\n");
    }
    printf("\n");

//3
    char ch = 'A' + num;
    char chr = ch;
    for (i = 0; i < num; i++){
        for(j = 0; j <= i; j++, chr--){
            printf("%c",chr);
        }
        printf("\n");
        chr = ch;
    }
    printf("\n");

//4
    printf("Enter another number: ");
    scanf("%d",&num);
    fflush(stdin);
    ch = 'A';
    for (i = 0; i < num; i++){
        for(j = 0; j <=i; j++, ch++){
            printf("%c",ch);
        }
        printf("\n");
    }


//5
    char chl;
    printf("Enter a character (A-Z): " );
    scanf("%c",&ch);
    fflush(stdin);
    chr = ch - 'A';
    for (i = 0; i <= chr; i++){
        j = 0;
        while (j < chr - i){
            printf(" ");
            j++;
        }

        for (chl = 'A';chl <= 'A' + chr - j; chl++){
            printf("%c",chl);
        }
        chl -= 2;

        for (chl; chl >= 'A'; chl--){
            printf("%c",chl);
        }
        printf("\n");
    }
    printf("\n");

//6
    int inf, sup, temp;

    printf("Enter lower limit and upper limit(integer): ");
    scanf("%d %d",&inf,&sup);
    fflush(stdin);
    for(num = inf; num <= sup; num++){
        for (i = 1; i<= 3; i++){
            for (j = 1, temp = 1; j <= i; j++){
                temp *= num;
            }
            printf("%d ",temp);
        }
        printf("\n\n");
    }

//7
    char word[20];
    printf("Enter a word: ");

    for (scanf("%c",&ch), i = 0; ch != '\n'; scanf("%c",&ch),i++)
        word[i] = ch;

    for (j = i-1;j >= 0; j--)
        printf("%c", word[j]);
    return 0;

    fflush(stdin);

// 8 & 9
    double num_a,num_b,ans;
    printf("Enter number a and b (seperate a and b with a space, press q to quit): ");

    while (scanf("%lf%lf",&num_a,&num_b) == 2){
        ans  = calculate(num_a, num_b);
        printf("(a - b) / (a * b) = %lf",ans);
        printf("\n\nEnter number a and b: ");

    }

    fflush(stdin);


// ?
    int numlist[8];
    printf("Please enter 8 integer: ");
    for (i = 0; i < 8 && scanf("%d",&num) == 1; i++){
        temp = 1;
        if (num > 0 ){
            for (j = 0; j < num; j++)
                temp *= 2;
         }
         else if (num = 0){
                num = 1;
         }
         else{
            break;
         }
        numlist[i] = temp;
    }
    printf("\n");

    i = 0;
    do{
        printf("%d ",numlist[i]);
        i++;
    }while (i < 8 || scanf("%d",&num) == 1);

    fflush(stdin);



    return 0;
}

