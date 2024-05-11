#include "stdio.h"
#include "iostream"
#include <vector>

using namespace std;

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
        T item = this->back();
        this->pop_back();
        return item;
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.pop() << s.pop() << s.pop();
}