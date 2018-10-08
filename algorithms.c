#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

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
//--------------------------------------------------------------------------------

// O(1) -> the fastest option
unsigned int sum_of_arithmetic_progression(unsigned int *table, size_t size) {
  if (table == NULL || size == 0) {
    return 0;
  }
  return (table[0] + table[size - 1]) * size / 2;
}

// O(log n) => binary search
void binary_search()
{
    size_t size = sizeof(students) / sizeof(students[0]);
    display(students, size);

    // Before binary search we have to sort array
    // Quicksort: using pivot and two counters
    // time complexity = O(n log n), worst case O(n^2)
    // space complexity = O(log n)
    qsort(students, size, sizeof(students[0]), cmp);
    display(students, size);

    // Binary search -> the search range is divided by 2
    // time complexity = O(log n)
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

// O(n) -> check all elements of array
unsigned int sum_of_array(unsigned int *table, size_t size) {
  unsigned int sum = 0;
  for (unsigned int i = 0; i < size; ++i) {
    sum += table[i];
  }
  return sum;
}

int main(int argc, char **argv)
{
    // O(1)
    unsigned int rv = sum_of_arithmetic_progression(array, sizeof(array) / sizeof(array[0]));
    printf("Sum a.p. = %u\n\n", rv);

    // O(log n) < O(1)
    binary_search();

    // O(n) < O(log n)
    rv = sum_of_array(array, sizeof(array) / sizeof(array[0]));
    printf("\nArray sum = %u\n", rv);

    // O(n log n) < O(n)  and it is bad
    // TERRIBLE
    // O(n log n) > O(n^2) > O(2^n) > O(n!)

    return 0;
}
