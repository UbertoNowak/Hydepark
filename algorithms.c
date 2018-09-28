#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *students[] = {
    "John",
    "Bob",
    "Adam",
    "Zack",
    "Clay",
    "Hanna"
};

void display(const char **array, size_t size)
{
    for(int i = 0; i<size; ++i)
    {
        printf("Elem %d: %s,\n", i, array[i]);
    }
    printf("\n");
}

int cmp(const void *a, const void *b)
{
    const char **str_1 = (const char**) a;
    const char **str_2 = (const char**) b;
    return strcmp(*str_1, *str_2);
}

void example_1()
{
    size_t size = sizeof(students) / sizeof(students[0]);
    display(students, size);

    // Before binary search we have to sort array
    // Quicksort: using pivot and two counters
    // time complexity = O(n log n), worst case O(n^2)
    // space complexity = O(log2(n))
    qsort(students, size, sizeof(students[0]), cmp);
    display(students, size);

    // Binary search -> the search range is divided by 2
    // time complexity = O(log2(n))
    // space complexity = O(1)
    const char *unknown_key = "Frank";
    const char *known_key = "Clay";

    const char **rv =  (const char **) bsearch( &unknown_key, students, size, sizeof(students[0]), cmp);
    if(rv)
    {
        printf("Found key %s\n", *rv);
    }
    else
    {
        printf("Coudn't find key\n");
    }

    rv =  (const char **) bsearch( &known_key, students, size, sizeof(students[0]), cmp);
    if(rv)
    {
        printf("Found key %s\n", *rv);
    }
    else
    {
        printf("Coudn't find key\n");
    }
}

int main(int argc, char **argv) {

    example_1();
    return 0;
}
