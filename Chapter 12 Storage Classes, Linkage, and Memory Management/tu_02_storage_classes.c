/*
    This .c file covers the four storage schemes for variables

    1/ Storage schemes for variables
            C uses different combination of duration, scope and linkage to
                define storage schemes for variables. We will focus on 5 storage classes (storage schemes).

            Storage class       Duration        Scope       Linkage     How Declared
            --------------------------------------------------------------------------
            automatic           Automatic       Block       None        In a block

            register            Automatic       Block       None        In a block
                                                                        with keyword register

            static with         Static          File        External    Outside all functions
            external linkage

            static with         Static          File        Internal    Outside all functions
            internal linkage                                            with keyword static

            static with         Static          Block       None        In a block
            no linkage                                                  with keyword static
            --------------------------------------------------------------------------


            1// Automatic Variables
                By default, any variable declared in a block or function header has
                    automatic storage class.

                You can also define an automatic variable with the storage-class specifier auto.

                You might wanna do this because it's important not to change the storage
                    class of that variable, or to document that you are intentionally overriding
                    an external variable definition

                !! However, C++ has repurposed auto for a quite diffreent use, so just don't use it.

                Block scope and no linkage means that only the block in which the variable
                    is defined can access the variable by name.
                    (but still, you can use indirect access like address)

                Outside the scope, another function can use the same name to refer to a
                    different variable (object)

                e.g.
                int test(int m){
                    m = 1;                             // m in scope
                    for (int i = 0; i < 10; i++){      // m, i in scope
                        printf("i = %d;  ", i);
                    }
                    print("\nm = %d", m);              // m in scope, i gone
                    return m;
                }

                What if variable var_in inside a block has the same name as variable var_out outside the block?
                    Inside the block, the name designates var_in,
                    But when C comes outside the block, the name designates var_out.
                    This is called "hides the outer definition"

                e.g.
                int name = 42;
                printf("name in outer block, = %d\n, stored in %p \n", name, &name);       // >> 42, loc_1
                {
                    char *name = "Hello";                                                  // C hides the outer definition
                    printf("name in inner block, = "%s", stored in \n", name, &name);      // >> Hello, loc_2
                }
                printf("name in outer block, = "%s", stored in &p \n", name, &name);       // >> 42, loc_1
                while (name-- > 20){
                     int name = 100;
                     name++;
                     printf("name in while loop, = %d, stored in %p \n", name, &name)      // >> 101 (for 22 times), loc_3
                }
                printf("name in outer block, = %d\n, stored in %p \n", name, &name);       // >> 20, loc_1

                Explanation of the while loop
                /1  Block without braces
                    A while loop is a block, the loop body is a sub-block to the while loop block,
                        thus name defined in test condition is hidden in the loop body (name = 42 vs name = 100)

                    This is a C99 feature, and it works for if, for, do while... too.

                    e.g.
                    int i = 1;
                    printf("i = %d in the main block.\n", i);           // i = 1
                    for (int i = 2; i < 8; i++){                        // i = 2
                        int i = 12;
                        printf("i = %d in the loop body block\n", i);   // i = 12 for 6 times
                    }
                        printf("i = %d in the main block\n", i);        // i = 1


                /2  For each loop, there is a new name defined b/c each name inside the loop is automatic (thus having automatic duration),
                        thus name defined in one iteration will vanish after the iteration.

                    In the loop body, name is created and destroyed for 22 times

                    But somehow, they are stored in the same address.

                This is just an educational demonstration, so
                    DON'T CODE YOUR PROGRAM THIS WAY !!!


                One need to manually initialize an automatic variable var, o/w value of var will be
                    whatever happens to lie in the memory allocated to it.


            2// Register Variables
                With luck, register variables are stored in the CPU registers (more generally, fastest memory).
                    In this case, register variables can be accessed more rapidly than regular variables.
                    Register and automatic variables have the same type of scope, linkage, and storage duration.

                A register variable is stored not in memory but in register, so you can't take the address of a register variable.

                Declaring a register variable is more like a request instead of an order. The compiler will decide whether to take the request
                    and store it in fast memory, or simply ignore the request. If refused, the variable becomes an ordinry automatic variable,
                    but you still can't take its address.

                To declare one, use keyword: register
                e.g.
                register int n = 12;
                int boom(register int times);       // The parameters of a fn can also be register.

                Some data types like double can't be declared as register for they are too big for the register in a processor to hold.


            3// Static Variables with Block Scope
                Static means that the variable stays put in memory, not necessarily in value.
                    (const is the keyword that makes the value of a var immutable)

                Variables of this storage class have: block scope       directly accessible in block only
                                                      no linkage
                                                      static duration   stay in memory the whole time,
                                                                        even if compiler is outside the block
                    They are also known as "local static variable"


                e.g. 1
                int * nptr;
                {
                    static int var_1 = 23;          // var_1 is a static variable with block scope
                    nptr = &var_1;
                    printf("var_1 = %d\n", var_1);  // directly accessible inside the block
                }
                //printf("var_1 = %d\n", var_1);    // not directly accessible outside the block
                printf("var_1 = %d\n", *nptr);      // but indirectly accessible outside the block,
                                                    //      such as using a pointer
                *nptr = 99;
                printf("var_1 = %d\n", *nptr);      // static vars have static memory, not necessarily static value


                e.g. 2: static in a function

                void test(void){
                    int fade = 1;
                    static int stay = 1;

                    printf("fade = %d, stay = %d\n", fade++, stay++);
                }

                void main(void){
                    for(int i = 0; i < 3; i++){
                        test();
                    }
                }

                >>> output:
                fade = 1, stay = 1
                fade = 1, stay = 2
                fade = 1, stay = 3

                explanation of e.g. 2:
                Initialization of static variable will only be executed once before the program is executed.
                    Static / external vars are already in place after a program is loaded into memory.
                    Thus, the static initialization statement is actually not a part of test()

                This way, stay is only visible to test() during the whole running time.

                However, you can't use static for function parameters !!


            4// Static Variables with External Linkage
                Variables of this storage class have: file scope
                                                      external linkage
                                                      static storage duration

                This storage class is called "external storage class"
                    Variables of this type are called "external variables"

                To create such a variable, define it outside of any function
                    You can also use keyword extern to declare it.
                    This is mainly for documentation (to indicate that a variable is external)

                If a particular external variable is defined in one source code file and is used
                    in another file, declaring it with extern in the second file is mandatory

                e.g.
                int Maple = 12;           // external definition
                double Up[100];
                extern char Command;      // keyword extern is mandatory if Command is from another file

                void collect(void);

                int main(void)
                {
                    extern double Up[];   // optional declaration, for documentation use
                                          //    no need to give the array size here b/c already given in the declaration above

                    char Maple = 'A';     // if declared without extern, the compiler will create a separate automatic variable that hides the external variable
                                          //    Thus, var Maple here is not an external int but an automatic char
                                          //    But when outside its storage duration, external again.
                }

                int Item = 23;            // Item is external. Note that the location of its definition make it
                                          //    not visible to main() but still visible to collect().

                void collect(void){
                ...
                }

                Note that file scope may differ. Both Item and Maple have file scope, but they have different visibility.

                Initializing an external variable
                    -   External variables can be initialized explicitly
                    -   Without manual initialization, external variables are automatically initialized to 0
                    -   You can only use constant expression to initialize external variables.
                            Expression with variables can't be used to initialize external variables
                                (b/c initialization of an external variable takes place before other part of the source code
                                    is loaded to memory. Thus, there is no variable to use when initializing an external variable)
                            e.g.
                            extern int x1 = 23;             // ok, 23 is constant
                            extern size_t z = sizeof(int)   // sizeof is considered constant so long as its input is not a variable
                            extern int x2 = 2*x1;           // not ok, x1 is a variable

                Using an external variable

                /Extra: Definitions and Declarations
                What's the difference between definition and declaration?
                e.g.
                int tern = 1;               // definition and declaration
                void main(void)
                {
                    extern int tern;      // declaration
                }

                Here, tern is declared twice, but defined once.

                "int tern = 1;" is a definition and a declaration.
                    It is called "defining declaration"
                It causes storage to be set aside for the variable

                "external int tern;" is not a definition but a declaration.
                    It is called "referencing declaration"
                It simply tells the compiler to use the tern variable that has been created previously.
                    The keyword extern indicates that a declaration is not a definition b/c it instructs the
                    compiler to look elsewhere.

                rmk. Thus, don't use extern to create an external definition,
                    o/w no space will be allocated for the variable.

                An external var can only be initialized once at the definition statement

                When we need to compile multiple files, we may need to use static variable with external linkage.
                    e.g.
                    writing main()                                          in one file,
                            prototypes
                            definition declaration of external vars
                    writing definition of other functions          in other files
                            reference declaration of external vars
                    Then, compile them together.

                Among these file, only one file uses defining declaration of the var
                                  all but one files uses reference declaration of the var (keyword extern)
                The one with defining declaration should be loaded to memory earlier than other files (probably?)

            5// Static Variables with Internal Linkage
                Variables of this type have: static storage duration    stay till the end of the program
                                             file scope                 visible to the whole file
                                             internal linkage           name binding is valid in this single file only

                To create such a variable, define it outside of any functions with keyword static. The name binding is valid only
                    when it's in the file (more precisely, the translation unit) where it locate .

                Redeclaring a static variable won't change its linkage


            6// Storage-Class Specifier Roundup
                There are 6 keywords that are storage-class specifier:
                    auto           : auto can be used only for vars with block scope, which already have auto storage duration.
                                        Thus, it is used for documentation intent.

                    register       : register also can be used only for vars with block scope. It requests to minimize the access time for a var.
                                        It also prevent you from taking the address of the var.

                    static         : static creates an object with static storage duration (stay put all the time during the execution)
                                        objects with static storage duration can have different linkages and scopes

                    extern         : extern indicates that you are declaring a variable that has been defined elsewhere.
                                         If extern var has file scope, it must have external linkage
                                         If extern var has block scope, it may have external linkage  (defined elsewhere)
                                                                                    internal          (for documentation use)

                    _Thread_local  : ???

                    typedef        : typedef says nothing about memory storage. It's added merely for syntax reasons.

                You can't use more than one storage-class specifier in a declaration. Consequently, you can't use any other
                    storage-class specifier in a typedef declaration.
                One exception is _Thread_local, which can be used together with static and extern


            7// Storage Classes and Functions
                Functions also have storage classes.
                    A function can be external : the default, accessible to other files
                                      static   : accessible to the file containing it only
                                      incline  : see Chapter 16

                e.g. 3 prototypes of functions of different storage classes
                double gamma(double);               // external by default, defining declaration
                static double beta(int, int);       // static
                extern double delta(double int);    // external, reference declaration

                Why static functions?
                -   to use the same name of functions in different files (avoid name conflict)
                -   to create functions that are private to a particular module, therefore avoid
                        possible name conflicts or errors.

                Why keyword extern in function prototype?
                    To use a function defined in other files, the usual practice is to use the extern
                        keyword when declaring the function (i.e. use extern in function prototype).

            8// The "need to know" principle
                One of the golden rules of protective programming is the ¡°need to know¡± principle.
                    Keep the inner workings of each function as private to that function as possible,
                    sharing only those variables that need to be shared. (one reason to use static functions)






*/





