#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using namespace std;

class C
{
public:
    C()
    {
        cout << "Constructor called" << endl;
        this->i = 1;
        this->s = new char[32]{"Hello from constructor"};
    }

    C(const C &old)
    {
        cout << "Copy constructor called" << endl;
        this->i = old.i;
        this->s = new char[32];
        strcpy(this->s, old.s);
    }

    C(C &&old)
    {
        cout << "Move constructor called" << endl;
        this->i = old.i;
        this->s = old.s;
    }

    int i;
    char *s;
};

C createC()
{
    C c = C();
    c.i = 2;
    strcpy(c.s, "Hello from createC");
    return c;
}

int main()
{
    const C c1 = C();   // costructor
    C c2 = c1;          // copy constructor

    C c3 = createC();   // costructor + move constructor
    cout << "c3:" << endl;
    cout << "-int: " << c3.i << endl;
    cout << "-string: " << c3.s << endl;

    C c4 = move(c2);    // move constructor
    cout << "c4:" << endl;
    cout << "-int: " << c4.i << endl;
    cout << "-string: " << c4.s << endl;
}