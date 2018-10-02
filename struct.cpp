#include <iostream>

// Struct is collection (complex data type) of diffrent data types
// where members are public by default
struct diff_kinds_data_items
{
    int points;
    std::string test;
};

typedef struct
{
    int number;
    std::string name;
    diff_kinds_data_items *data;
} record;

void display_struct(record *s)
{
    std::cout << s->name << " have number " << s->number << " and his last "
              << s->data->test << " result is " << s->data->points << "\n";
}

void example_1()
{
    std::cout<<"\nEXAMPLE 1\n";

    // In C struct keyword is mandatory before declaration
    struct diff_kinds_data_items results;
    results.points = 15;
    results.test = "simple quiz";

    // In C++ struct keyword is optinal
    diff_kinds_data_items results_2;
    results_2.points = 5;
    results_2.test = "hard quiz";

    record student;
    student.number = 1;
    student.name = "Bob";
    student.data = &results;

    display_struct(&student);
}

// Class is user defined type, where members are private by default
class Student
{
public:
    Student(int number, std::string name) : m_number(number), m_name(name) {}
    void display();

private:
    int m_number;
    std::string m_name;
};

void Student::display()
{
    std::cout << m_name << " have number " << m_number << "\n";
}

void example_2()
{
    std::cout<<"\nEXAMPLE 2\n";
    Student John(42, "John");
    John.display();
}

int main(int argc, char **argv)
{
    example_1();
    example_2();
    return 0;
}
