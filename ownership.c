#include <stdio.h>
#include <stdlib.h>

// Objects liftime:
// a) static
// b) automatic
// c) dynamic

// static
// allocated in compile/link time in two sections
int global_a;// = 0     // uninitialized-definitions -> .bss or ZI
int global_b = 42;      // initialised-definitions -> .data or RW

// automatic: return value, ptr, local, automatic
int fun(int **ptr, int local) {
  int automatic = global_a;
  // dynamic: memory allocated by the call malloc
  *ptr = (int *)malloc(sizeof(int));
  **ptr = global_b;
  local = automatic;
  return local;
}

void example_1() {
  int *p, x = 0;
  int rv = fun(&p, x);
  printf("Return value: %i, ptr: %i, local: %i\n", rv, *p, x);
  free(p);
}

int main(int argc, char **argv) {
  example_1();
  return 0;
}

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
