#include <QObject>
#include <boost/bind.hpp>
#include <boost/signal.hpp>
#include <iostream>

class Qt_Counter : public QObject
{
    // You have to add this macro in private part of class if you want to
    // use signals and slots
    Q_OBJECT

public:
    Counter(int value) : m_value(value) {}

    int get_value() { return m_value; }

public slots:
    void set_Value(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};

void Qt_Counter::set_Value(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value); // register an event
    }
}

void example_1()
{
    Qt_Counter a, b;
    QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));

    a.setValue(12);
    std::cout << "Counter a: " << a.get_value()
              << ", counter b: " << b.get_value() << "\n";
    b.setValue(48);
    std::cout << "Counter a: " << a.get_value()
              << ", counter b: " << b.get_value() << "\n";
}

struct ClassA
{
    boost::signal<void()> SigA;
    boost::signal<void(int)> SigB;
};

struct ClassB
{
    void PrintFoo() { std::cout << "Foo\n"; }
    void PrintInt(int i) { std::cout << "Bar: " << i <<"\n"; }
};

void example_2()
{
    ClassA a;
    ClassB b, b2;

    a.SigA.connect(boost::bind(&ClassB::PrintFoo, &b));
    a.SigB.connect(boost::bind(&ClassB::PrintInt, &b, _1));
    a.SigB.connect(boost::bind(&ClassB::PrintInt, &b2, _1));

    a.SigA();
    a.SigB(4);
}

int main(int argc, char **argv)
{
    example_1();
    example_2();
    return 0;
}
