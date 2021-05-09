#include <stdio.h>


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



char ** bubble_sort(char *input_str[], const int LEN)

{
    int i, j;
    char *temp;


    for(i = 0; i < LEN - 1; i++){
        for(j = 0; j < LEN - 1; j++){
            if (strcmp(input_str[j], input_str[j+1]) > 0){
                temp = input_str[j+1];
                input_str[j+1] = input_str[j];
                input_str[j] = temp;
            }
        }
    }
    return input_str;
}



char **quick_sort(char *input_str[], const int LEN)
{
    char *org_input[] = input_str;  // original input
    char *curr_cpy[] = input_str;   // current copy

    int i,j,k, opivot, spivot;      // original pivot and sorted pivot
    char *temp;

    for (i=0, j=opivot=spivot=0, k=pivot; i < LEN; i++){
        if (strcmp(org_input[i], strcmp(org_input[opivot]) > 0)){
            spivot++;
        }
    }
    input_str[]

    return input_str;
}

char **

sth = partition(left_start, left_end, sth);
sth = partition(right_start, right_end, sth);





int main(void)
{

/*
   Part 5. Program: sorting string alphabetically

    Basically, this program take an array of string as input
        and sort the strings alphabetically

    The program consists of three parts: string input
                                         string sorting
                                         string output
    I will use two algorithms to do the sorting
    bubble sort and quick sort

*/

    char *input_str[]= {"Orange","Apple",
    "Pineapple", "Apple", "Swan", "Bravo"};
    const int LEN = sizeof(input_str) / sizeof(char*);
    // to calculate the length of the input_str

    int i;
    for (i = 0; i < LEN; i++){
        puts(*(input_str + i));
    }

/*
    1// Bubble Sort
    Bubble sort is an inefficient but easy sorting algorithm
        It compares each two neighboring entries,
        if L > R, then swap.
        else do nothing.

    time complexity     O(n^2)
*/

    //char **input_str_1 = input_str;
    //char **bubble_sorted_str = bubble_sort(input_str_1, LEN);
/*
    A technical detail:
        Since it's impossible to actually let a function
            return an array of pointer,
        we return a pointer of a char pointer (char **) instead
            and bubble_sort will thus be an char ** function
*/
    //puts("\n");
    //for (i = 0; i < LEN; i++){
        //puts(bubble_sorted_str[i]);
    //}


/*
    2// QuickSort
    QuickSort is a more efficient algorithm

*/

    char **input_str_2 = input_str;
    char **quick_sorted_str = quick_sort(input_str_2, LEN);

    puts("\n");
    for (i = 0; i < LEN; i++){
        puts(bubble_sorted_str[i]);
    }


    return 0;
}


















