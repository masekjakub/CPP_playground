#include <iostream>

using namespace std;

void print(int &&value)
{
    cout <<"Rval: "<< value << endl;
}

void print(int &value)
{
    cout << "Lval: " << value << endl;
}

int main()
{
    int b = 2;
    int &B = b;
    int &&A = 1;

    print(A);
    print(B);
    print(3);

    return 0;
}