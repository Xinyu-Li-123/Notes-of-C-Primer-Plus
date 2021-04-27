# include <stdio.h>

/*
char is the data type for characters like letters and punctuations.
However, they're in fact also integer b/c they are encoded by ASCII.
e.g. char a = A. What stored in the memory is not the character A (you can't store a character in the memory),
                But integer 65, since by ASCII, 65 <=> A
*/


int main(void)
{
    char book = 'A';                            // use char var_name = 'A' to declare a character   character: ''
    printf("That book is %c\n",book);           // use char var_name = 'A' to declare a character
    printf("That book in ASCII is %d\n",book);  // since char book is an integer, we can use it as a integer
    char ASCII_code = 67;                            // assign ASCII to the character, valid but poor style
    printf("67 represents %c in ASCII\n",ASCII_code);
    char food[] = "Apple pie";                  // use char var_name[] = "Apple pie" to declare a string (character array)
                                                                                                //  string: ""
    printf("The dinner today is %s\n",food);
// For the big list of escape sequences, see C Primer p73
// You can assign an escape sequence to a character
    char alert = '\a';
    // \a is for alert
    printf("%c",alert);


    return 0;
}
