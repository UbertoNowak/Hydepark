#include <iostream>

// A reference is an alias, or an alternate name to an existing variable
void display(int val, int &ref, int *ptr)
{
    std::cout<<"In funciton -> ref: "<< ref <<", ptr: "<< *ptr <<"\n"; // ypu don't have to dereference ref.
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

    display(ref_x, y, &z);
    std::cout<<"Main function -> copy: "<< ref_x <<", ref: "<< y <<", ptr: "<< z <<"\n";
}

int main(int argc, char **argv)
{
    example_1();
    return 0;
}
