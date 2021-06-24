#include <stdio.h>

/* This .c file covers the basic knowledge of storage classes.
    Storage class can help us better understand the difference between parameter (formal arg) and argument (actual arg). */

void main(void)
{
/*  Part 0. Basic concepts
    - Object (hardware aspect):
        An object is a chunk of physical memory that can store some kind of value
        (
         rmk. object in C  vs  object in OOP language)
             Objects in OOP is more developed. They indicate class objects, which can store
                both data and permissible operations on the data.
             C is not an OOP languange
         )

    - Identifier (software aspect):
        int entity = 3;
        entity is an identifier, a name that can be used to designate
            the content of a particular object
        Software (C program) uses identifiers to designate (specify) hardware memory (objects)
        The initialization also provides a value to be stored in the object.

        Variable name is not the only way to designate an object.
        e.g.
        int *pt = &entity;
        int ranks[10];

        *pt is not an identifier (i.e. not a name), but it can designate the same object
            designated by entity

    - name binding
        name binding is an association of an identifier (name) to an entity (object))

    - lvalue:
        An lvalue is an expression that designates(specifies) an object
        i.e. lvalue must have address (identifiable in memory)
            e.g.
            entity is an lvalue
            *pt is also an lvalue
            ranks + 2*entity is neither an identifier nor an lvalue
            *(ranks + 2*entity) is an lvalue

        ranks is an int array. ranks is an object that can hold 10 ints,
            each of its entry is also an object

        if you can use the lvalue to change the value of an object,
            then it's a modifiable lvalue
            e.g.
            char arr[] = "word";      // arr is a modifiable lvalue
            const char *str = "word"; // str is a modifiable lvalue
                                      //    (point to a different string)
                                      // *str is not a modifiable lvalue
                                      //    (in that string literal is constant)
            // Interestingly, the string literal "word" is itself an lvalue
            //      b/c it designates the object that holds the char string,
            //      but it's not modifiable.
*/

/* Part 1. Anatomy of storage classes

    We can describe an    object        with    storage duration
                          identifier            scope & linkage
                                                (indicating which part of the program
                                                    can use this identifier)

    Different storage classes offer different combinations of scope, linkage, and storage duration

    Scope and linkage describe the visibility of identifiers
    Storage duration describes the persistence ("lifespan") of the objects accessed by these identifiers

    1/ Scope
        the scope of a name binding is the part of a program where the name binding is valid,
            that is where the name can be used to refer to the entity

        In other parts of the program the name may refer to a different entity (name with different binding)
            or to nothing at all (unbound name).

        A C variable has one of the four following scopes
            block scope
            function scope
            function prototype scope
            file scope

        Block scope:
            A variable defined inside a block has block scope
            It is only visible to the program (accessible) inside the block
            e.g.
            void main(void)
            {

            1//
            int i = 10;

                // identifier i has a block scope,
                //      visible from the point it is defined
                //      to the end of the block containing its definition (the main() block)


            2//
            {
                printf("k = %d", k);        // invalid call, k is undefined
                int k = 3;
                printf("k = %d", k);        // valid call, k is defined

                // identifier k has a block scope
                //      visible from the point it is defined
                //      to the end of the block containing its definition
            }

            3//
            for(int h = 10; h >0; h--)
                // With the C99 update, you can define sth inside the for( )
                // the same identifier h is visible inside all iteration of this for loop

                int j = h;

                // identifier j has a block scope,
                //      each j is visible inside the corresponding iteration (j has a "lifespan" of one iteration)
                // !! NOTE: when j = 3, j is only visible inside the iteration where h = 3


            printf("i = %d,  j = %d,   k = %d");
            //      valid    invalid   invalid
            }


        Function scope
            It's used for label in goto, but no one is using it, so we'll skip it


        Function prototype scope
            Function prototype scope applies to variable names used in function prototype
            e.g.
            int sumfoo(int foo_1, int foo_2)
            foo_1 and foo_2 have function prototype scope
                They are only visible inside the prototype declaration
                So, normally, their name doesn't really matter

            But in the case below, the name does matter.
            void printString(int n, char arr[n])    // valid
            void printString(int m, char arr[n])    // invalid b/c name doesn't match
            void printString(char arr[n], int n)    // invalid b/c wrong order of definition


        File scope
            A variable with its definition placed outside of all function has file scope.
                visible from the point it is defined to the end of the file containing the definition

            Variables with file scope are usually called global variables

            e.g.
            // This is a file called CipherToText.c
            //      It transform ciphers to text.
            char type[10] = "Morse"     // a string indicating the type of the code
            static char *ENDNOTE = "This is the end of the decoding process"

            char* MorseToText(char *code);
            char* ASCIIToText(char *code);
            char* RunesToText(char *code);
            char* ShiftToText(int shift, char *code);

            void main(void)
            {
                ...
            }
            ... // prototype definitions

            Here, ENDNOTE and type have file scope, i.e. they are two global variables


        Translation Units and Files
        A translation unit is one single file that replaces the #includes
            with the header files included in the source code file.

        You may have included many header files involved in the source code, but after translation,
            they will merge into one single file called translation unit.

        And a variable with file scope is actually visible to this translation unit.


    2/ Linkage
        Linkage describes how names can or can not refer to the same entity
            throughout the whole program or one single translation unit.

        A C variable has one of the following three kinds of linkages
            external linkage
            internal linkage
            no linkage

        Variables with block scope, function scope, or function prototype scope
            have no linkage, i.e. they are private to the block, function, or prototype
            in which they're defined.

        Variables with file scope have either external linkage or internal linkage.
            A variable with external linkage can be used anywhere in a multi-file program
            A variable with internal linkage can be used anywhere in a single translation unit

        Abbreviation:
            file scope with internal linkage --> file scope
            file scope with external linkage --> global / program scope

        static
            static is a storage class specifier. It restricts the visibility of a function or variable
                to its translation unit (i.e. internal linkage).

            In the external definition,
                with static     ==>   internal linkage (e.g. ENDNOTE)
                without static  ==>   external linkage (e.g. type)


    3/ Storage Duration
        Storage duration describes the lifetime of a storage containing an object

        A C variable has one of the following four kinds of storage duration:
            static storage duration
            thread storage duration
            automatic storage duration
            alloated storage duration

        static storage duration:
            variables exist till the end of the program execution
            e.g. var with file scope
                 static declaration inside a function
                (rmk. specifier static indicate the linkage type, not the storage duration
                 With or without static, a file-scoped object always has static storage duration)

        thread storage duration:
            used in concurrent programming (diff from parallel programming) where program execution
                is divided into multiple threads

            Exists from which it's declared to the end of the thread containing it.

            To create an object with thread storage duration, use
                _Thread_local at the beginning of a file
                This way, each thread gets its very own private copy of that variable
                    (Modification in one thread won't affect another)

            Extra: concurrent vs parallel
                concurrent(并发): 1 CPU,  n threads (thread = task). Divide the running time of CPU
                                        into n pieces, them run each piece accordingly
                                 n threads executed within the same time periods

                parallel(并行)  : n CPU,  n threads. Executed at the same time.
                                        No competition for resources between CPUs
                                 n threads executed at the same sec

                Their efficiency can be measured by QPS (Queries Per Second)
                                                    TPS (Translation Per Second)

        automatic storage duration:
            Block-scoped vars normally have automatic storage duration.

            They are stored in run-time stack. The memory is allocated for them when the program enters the block where they're defined
                and freed when the program exits that block.

            The idea is that memory for automatic vars is like a workspace or scratch pad that can be reused.
                e.g.
                After a function terminates, the memory it used for the auto var can be freed
                    and used for other variables of the next function called.

            variable-length array is an exception, it starts not from the beginning of a file
                but from the point of declaration.

            The local variables we've used so far fall into the automatic category

            e.g.
            void squareMultipleInt(int times){      // times has block scope automatic storage duration
                static int arr[times];              // arr has block scope and static storage duration
                for(int i = 0; i < times; i++){     // i and j have block scope and automatic storage duration
                    int j = i*i;
                    arr[i] = j;
                }
            }

            rmk. arr has block scope and static storage duration, which means
                     it will exist till the end of the program,
                     but only accessible by the function squareMultipleInt()
                 But one can use indirect access like address and returned value.

         allocated storage duration
            see ???

