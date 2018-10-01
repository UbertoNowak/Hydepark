#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

void display( int *array, size_t size)
{
    for(int i = 0; i<size; ++i)
    {
        std::cout<<"Elem "<< i <<" of array is: "<< array[i] <<"\n";
        array[i] += 10;
     }

}

void example_1()
{
    std::cout<<"\nEXAMPLE 1\n";
    int tab[5] = {1, 2, 3, 4, 5};
    display(tab, sizeof(tab)/sizeof (*tab));
    display(tab, sizeof(tab)/sizeof (*tab));
}


void display_arr_items(std::array<int, 9> &arr) {
    std::cout << "First elem.: " << arr.front() << ", second: " << arr[1]
              << ", third: " << arr.at(2) << ", last: " << arr.back() << "\n";
}

void display_arr(std::array<int, 9> &arr) {
    for (auto &&i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void example_2() {
    std::cout<<"\nEXAMPLE 2\n";

    // NOTE: std:array is availble since c++11
    std::array<int, 9> tab = {{9, 5, 6, 8, 7, 3, 4, 2, 1}};
    display_arr_items(tab);

    // iterators
    std::sort(tab.rbegin(), tab.rend());
    display_arr_items(tab);

    std::sort(tab.begin(), tab.end());
    display_arr_items(tab);

    tab.fill(0);
    display_arr(tab);

    std::array<std::array<int, 3>, 3> tab2d = {
        {{{1, 2, 3}}, {{11, 12, 13}}, {{21, 22, 23}}}};
    std::cout << "Tab2d size: " << tab2d.size()
              << ", is empty: " << (tab2d.empty() ? "true" : "false") << "\n";
    std::cout << "Tab2d first: " << tab2d.at(0).at(0) << ", last: " << tab2d[2].back()
              << "\n";
}

void display_vector(std::vector<int> &v)
{
    for(auto &&i : v)
    {
        std::cout<< i <<", ";
    }
    std::cout<<"\n";
}

void example_3() {
    std::cout<<"\nEXAMPLE 3\n";

    std::vector<int> v = {1, 2, 3};
    display_vector(v);
    v.pop_back();
    v.push_back(42);
    v.insert(v.begin(), 0);
    std::cout<<"Vector size: "<< v.size() <<", capacity: "<< v.capacity() <<"\n";
    display_vector(v);
    v.clear();

    display_vector(v);
    std::cout<<"Vector size: "<< v.size() <<"\n";
}

int main(int argc, char **argv) {
    example_1();
    example_2();
    example_3();
    return 0;
}

