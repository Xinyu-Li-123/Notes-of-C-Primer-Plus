include <stdio.h>



void main(int argc, char **argv)    // char **argv is equiv to char *argv[]
{
/*
    main can takes two arguments: argc and argv (argument count / value)
    The system uses spaces and " " to identify a string.

    e.g.

    C> gcc -o print_str.exe tu_99_print_str.c
    C> print_str Hello world! "I'm here."
    You have entered 4 strings.
    #0: print_str
    #1: Hello
    #2: world!
    #3: 'I'm here'

    Note that the executable file name is also
        counted as the input of print_str.exe



*/
    if (argc > 1){

        int i;

        printf("You have entered %d strings.\n", argc);

        for (i = 0; i < argc; i++){
            printf("#%d: %s\n",i,argv[i]);
        }
    }
    else{
        printf("Error: There is no input except the file name.");
    }
}
