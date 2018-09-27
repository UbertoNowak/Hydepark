#include <stdio.h>

#define preprocesor_const 42

void modify_ptr_to_char(const char **ptr) {
    *ptr = "New text after modify ptr to char";
    printf("modify str: %s\n", *ptr);
}

void example_1() {
    printf("\nEXAMPLE 1\n");

    const char *str = "This str is stored in read only block";
    printf("str: %s\n", str);
    modify_ptr_to_char(&str);
    printf("str: %s\n", str);
}

void example_2() {
    printf("\nEXAMPLE 2\n");

    // We can change value of ptr and value pointed by ptr
    int x = 5, y = 10;
    int *ptr = &x;
    ptr = &y;
    *ptr = 15;

    // We can change value of ptr but we CAN'T change value pointed by ptr
    const int *ptr_c_i = &x;
    ptr_c_i = &y;
    // error: assignment of read-only location
    //*ptr_c_i = 15;
    int const* ptr_c_v = &y;
    // NOTE: The order in which the declaration specifiers appear in a declaration doesn’t matter

    // We CAN'T change value of pointer, but we can modify value poited by ptr
    int* const c_ptr = &x;
    *c_ptr = preprocesor_const;
    //error: assignment of read-only variable
    //c_ptr = &y;

    // We can fix both, and can't change anything;
    const int* const c_ptr_c_i = &x;
    //c_ptr_c_i = &y;   //error: assignment of read-only variable
    //*c_ptr_c_i = 42;  //error: assignment of read-only location
}

int main(int argc, char **argv) {

    example_1();
    example_2();

    return 0;
}
