#include "stdio.h"
#include "iostream"
#include <vector>

using namespace std;

// Stack – adapter, vector – adaptee
template <typename T>
class Stack : private vector<T>
{
public:
    void push(T item)
    {
        this->push_back(item);
    }

    T pop()
    {
        if (this->isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        T item = this->back();
        this->pop_back();
        return item;
    }

    bool isEmpty()
    {
        return this->empty();
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty())
    {
        cout << s.pop() << endl;
    }
    //s.pop(); // This will throw an exception
    return 0;
}