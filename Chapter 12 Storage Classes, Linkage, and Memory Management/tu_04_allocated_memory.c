/* This .c file covers knowledge of allocated memory */

#include<stdio.h>
#include<stdlib.h>  /* for malloc(), free(), exit()*/

int static_store = 30;
const char* pcg = "String Literal";

int main(void)
{

/*
    1/ Allocated Memory
    When using storage class, the decisions about scope and storage duration follow automatically.

    There is, however, one more choice that provides more flexibility. That choice is using
        library functions to allocate and manage memory: malloc() and free() in stdlib.h.

    1// malloc():
        malloc() takes one arg: the number of bytes of memory you want. It then finds a
            suitable block of free memory. This block of memory is anonymous b/c malloc()
            doesn't assign a name to it. However, it does return the address of the first
            byte of that block. T/f, you can assign that address to a pointer to create a
            name binding.

        malloc() is type pointer-to-void. This roughly means a "generic pointer" b/c
            assigning a pinter-to-void value to a pointer of another type isn't considered a type clash.
            It will typecast to the proper value automatically.
            (m is for memory)

        rmk. pointer-to-xxx means a pointer of xxx data type.
                e.g. pointer-to-double is a pointer of double data type

        If malloc() fails to find the required space, it returns the null pointer.

        e.g. defining an array of 30 doubles

*/
    double *ptd;
    ptd = (double *) malloc(30 * sizeof(double));   /* set space for 30 double, equiv to "double ptd[30];"*/
    ptd[3] = 3.14159265;

/*
        Thus, now we have 3 ways to define an array
        -   Declare an array using constant expressions for the array dimensions,
                and use the array name to access elements.
            Such an array can be created using either static or automatic memory
            e.g.
            static int num[5] = {1,2,3,4,5};

        -   Declare a variable-length array using variable expressions for the array dimensions
                and use the array name to access elements.
            Such an array can be created using automatic memory only b/c static memory is loaded
                before memory of variables.
            e.g.
            int i = 5;
            int num[i] = {6,7,8,9,10};

        -   Declare a pointer, call malloc(), assign the return value to the pointer,
                and use the pointer to access elements.
            The pointer can be either static or automatic
            e.g.
            see above

        Dynamic Array:
        You can use the 2nd or 3rd way to create a dynamic array: one that¡¯s allocated
            while the program runs and that you can choose a size for while the program runs.
        e.g.
            For a varying n (say n goes from 1 to 10 as time passes by)
            double item[n];
            // not okay b/c the array is static (allocated memory stays put)

            double *item = (double *) malloc(n * sizeof(double));
            // okay

    2// free()
        Normally, you should balance each use of malloc() with a use of free(). free() takes
            an address returned by malloc() and frees up the memory allocated.

        Thus the duration of the allocated memory is from malloc() to free()

        The argument of free() should be a pointer of a block of memory allocated by malloc(). You can use different pointers
            as arg of free() so long as they point to the address of memory allocated by malloc().
        e.g.
*/
    double *ptd_1;
    int max = 0;
    int number;

    printf("Enter double array size: ");
    if(scanf("%d", &max)!= 1){
        puts("Number not correctly entered. Bye.");
        //exit(EXIT_FAILURE);
    }

    ptd_1 = (double *) malloc(max * sizeof(double));

    if(ptd_1 == NULL){
        puts("Memory allocation fails. Bye.");
        //exit(EXIT_FAILURE);

    }

    for(int i = 0; i < max; i++){
        printf("Please enter the #%d element of the array: ", i+1);
        scanf("%lf", &ptd_1[i]);
    }

    puts("\nThe double array you entered is:");
    for(int i= 0; i < max; i++){
        printf("%.2f  ", ptd_1[i]);
    }
    printf("\n\n");
/*
    /Extra: exit()
    exit() is prototyped in stdlib.h. It can terminate the program.
    The two value EXIT_FAILURE and EXIT_SUCCESS, also in stdlib.h, is guaranteed to
        work with all OSs.
    EXIT_SUCCESS (equiv, 0) indicates normal program termination.
    EXIT_FAILURE (equiv, !0) indicates abnormal program termination.


    Why Dynamic Array?
        B/c it provides more flexibility. Say you want to store int in an array. Normally you
            only need 100 entries, but sometimes you need 10000 entries. Without dynamic array,
            you will have to declare an 10000-entries int array. But with dynamic array, you can
            change the size of the array based on the need.

    The Importance of free():
        Memory allocated by malloc() need to be freed manually (in contrast to auto var).
            Without free(), the program may run out of memory and cause a memory leak.

    3// calloc()
        calloc() is similar to malloc(). It takes in two unsigned long, allocates some memory, and return an address
        e.g.
            long * ptr = (long *) calloc(100, sizeof(long);
            // using sizeof(double) instead  4 bytes makes the program more portable b/c size of long may differ
                    in diff OSs.

        calloc() has one more feature: it initialize each bits to 0 of the corresponding type.
            (note that 0 in double may not be repr. as 0)


    4// Variable-Length Array and Dynamic Memory Allocation
        You can declare a VLA using either explicit declaration or malloc()
*/


    int row = 2;
    int col = 3;
    int arr_1[row][col];
    // explicit declaration
    int (*arr_2)[col];
    arr_2 = (int (*)[col]) calloc(row*col,sizeof(int));
    // declaration using malloc()

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr_2[i][j]);
        }
        printf("\n");
    }

/*
    5// An idealized model for memory allocation
        You can think of a program as dividing its available memeory
            into three seperate sections:   static var with diff linkage
                                            automatic var
                                            dynamically allocated memeory

        To see how these three sections are divided, run the following e.g.
        e.g.
*/

    int auto_store = 40;
    char auto_string[] = "Auto char Array";

    int * pi = (int *) malloc(sizeof(int));
    *pi = 35;
    char *pcl = (char *) malloc(strlen("Dynamic String" + 1));
    strcpy(pcl, "Dynamic String");

    printf("\nStatic var\nstatic_store:%d at %p\n", static_store, &static_store);
    printf("\"%s\" at %p\n",pcg,pcg);

    printf("\nAuto var\nauto_store: %d at %p\n", auto_store, &auto_store);
    printf("%s at %p\n", auto_string, auto_string);

    printf("\nDynamically allocated var\n");
    printf("%s at %p\n", pcl, pcl);
    printf("*pi: %d at %p\n", *pi, pi);

/*
    -   automatic vars are stored in stack, a last-come-first-leave way to store memory.
    -   dynamically allocated memory is stored in a region called memory heap or free store.
*/


    return 0;
}
