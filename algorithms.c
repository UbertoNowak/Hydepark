#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *list[] = {
    "John",
    "Bob",
    "Adam",
    "Zack",
    "Clay",
    "Hanna"
};

void display_list(const char **list, size_t size)
{
    for(int i = 0; i<size; ++i)
    {
        printf("Elem %d: %s,\n", i, list[i]);
    }
    printf("\n");
}

int cmp(const void* a, const void* b)
{
    const char** str_1 = (const char**) a;
    const char** str_2 = (const char**) b;
    return strcmp(*str_1, *str_2);
}

void example_1()
{
    size_t size = sizeof(list) / sizeof(char *);
    display_list(list, size);

    // Before binary search we have to sort array
    qsort(list, size, sizeof(char *), cmp);
    display_list(list, size);
}

int main(int argc, char **argv) {

    example_1();
    return 0;
}
