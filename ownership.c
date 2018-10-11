#include <stdio.h>
#include <stdlib.h>

// Objects liftime:
// a) static        -> on data segment (.bss + .data)
// b) automatic     -> on stack
// c) dynamic       -> on heap

// static
// allocated in compile/link time in two sections
int global_a;      // = 0     // uninitialized-definitions -> .bss or ZI
int global_b = 42; // initialised-definitions -> .data or RW

// automatic: return value, ptr, local, automatic
// NOTE: temporary-returned-object(TRO)
static int fun(int **ptr, int local)
{
    int automatic; // garbage !!!
    automatic = 0;

    // dynamic: memory allocated by the call malloc
    // lifetime is under the control of the programmer
    // NOTE: in C standard dynamic allocated objects are also called automatics
    *ptr = (int *)malloc(sizeof(int));

    **ptr = global_b;

    static int static_local = 0; // only first time, and only const value
    // const int x = 5;
    // static int static_local = x;   // Error
    local = ++static_local;
    // NOTE: local static varaible may generate problems in
    // multi-task/multi-threading environment, and should generally be avoided

    return local;
}

static void example_1()
{
    int *p, x = 0;
    int rv = fun(&p, x);
    printf("Return value: %i, ptr: %i, local: %i\n", rv, *p, x);
    rv = fun(&p, x);
    printf("Return value: %i, ptr: %i, local: %i\n", rv, *p, x);
    free(p);
}

// Scope
// a) File scope
// b) Block scope

// in file scope you can access varaible after declaration
static void fun_first()
{
    // int x = global_c;    // Error -> global_c not visible
}

int global_c = 42;        // external linkage – global scope
static int global_d = 17; // internal linkage – this-file scope

extern int global_e; // when you use a global from another file

// all functions have external linkage by default so use static
static void fun_second()
{
    int y = global_c;
    {
        int block_scope = global_c;
        static int static_block = 42;
    }
    // y = block_scope;  // Error
    // y = static_block; // Error
    int global_c = 13;
    printf("block global_c: %i\n", global_c);

    {
        extern int global_c; // In C++ you can use ::global_c
        printf("glob global_c: %i\n", global_c);
    }
}
// NOTE: dynamic varaibles have scope of pointer which holding the adress of
// synamically allocated memory

static void example_2()
{
    fun_second();
}

// NOTE: translation unit is source file after preprocessing and before
// compiling
// External linkage refers to things that exist beyond a particular translation
// unit. In other words, accessible through the whole program, Internal linkage
// refers to everything only in scope of a translation unit.

int main(int argc, char **argv)
{
    // example_1();
    example_2();
    return 0;
}

// NOTE: realloc free old content

// NOTE: in C language the term "constant" refers to literal constants (like  1,
// 'a', 0xFF and so on), enum members and results of such operators as sizeof.
// Const-qualified objects (of any type) are not constants in C language
// terminology.

// NOTE: Data segment of simple program
/* __________________________________
 * |              Stack             |
 * |    -   -   -   -   -   -   -   |
 * |                                |
 * |                                |
 * |                                |
 * |    -   -   -   -   -   -   -   |
 * |              Heap              |
 * |--------------------------------|
 * |              BSS               |
 * |--------------------------------|
 * |              Data              |
 * |--------------------------------|
 * |        Text (code segment)     |
 * |________________________________|
 * */
