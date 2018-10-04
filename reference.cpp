#include <iostream>

// A reference is an alias, or an alternate name to an existing variable
void display(int val, int &ref, int *ptr)
{
    std::cout<<"In funciton -> ref: "<< ref <<", ptr: "<< *ptr <<"\n"; // you don't have to dereference ref.
    val = 55;   // copy of varaible
    ref = 99;
    *ptr = 777;
}

void example_1()
{
    std::cout<<"\nEXAMPLE 1\n";
    int x = 42, y = 1, z =2;
    //int &bad_ref;     // initialize the reference during declaration -> diff then pointers
    int &ref_x = x;     // when you assign varaibe to reference, no adress needed
                        // when you create reference you don't create new variable in source code, just
                        // another alias of existing varaible
                        // You can't change reference variable to ref.

    // Can't assign NULL to reference -> diff then pointers
    // int &ref_y = NULL

    display(ref_x, y, &z);
    std::cout<<"Main function -> copy: "<< ref_x <<", ref: "<< y <<", ptr: "<< z <<"\n";
}

int& function_1(int& x)
{
    return ++x;   // OK, x is outside this scope
}

int& function_2()
{
    int i;
    return i;   // ERROR, scope of q ends here
}

int& function_3()
{
    static int x = 42;
    return x;   // OK, x is static, so it lives till the end
}

void example_2()
{
    int value = 5;
    function_1(value);
    int x = function_3();
    std::cout<<"value: "<< value <<", x: "<<x<<"\n";
}

int main(int argc, char **argv)
{
    example_1();
    example_2();
    return 0;
}
