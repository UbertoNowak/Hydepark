#include <stdio.h>

void example_1()
{
    printf("\nEXAMPLE 1\n");

    int x = 42;
    int *px = &x;
    int **ppx = &px;

    printf("Arg x: %d, adres x: %p\n", x, &x );
    printf("Deref px: %d, arg px: %p, adres px: %p\n", *px, px, &px);
    printf("Deref *ppx: %d, deref ppx: %p,\n  arg ppx: %p, adres ppx: %p\n", **ppx, *ppx, ppx, &ppx);
}

void good_allocate(int** p)
{
    *p = (int*)malloc(sizeof(int));
    **p = 42;
}

void bad_allocate(int* p)
{
    p = (int*)malloc(sizeof(int));
    *p = 52;
}

void example_2()
{
    printf("\nEXAMPLE 2\n");

    int x = 99;
    int* p = &x;
    bad_allocate(p);
    printf("*p = %d, p = %p, &p = %p\n", *p, p, &p);

    good_allocate(&p);
    printf("*p = %d, p = %p, &p = %p\n", *p, p, &p);
    free(p);
}

int main(int argc, char** argv)
{
    for(int i = 1; i<argc; ++i)
        {
            printf("%s, ", argv[i]);
        }

    example_1();
    example_2();


    return 0;
}
