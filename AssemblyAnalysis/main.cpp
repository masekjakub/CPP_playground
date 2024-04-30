#include <iostream>

int main()
{
    int a = 1;
    int arr[3]{0};
    for (int i = 0; i < 3; i++)
    {
        a*=2;
        arr[i] = i;
    }


    return (a+arr[1])*arr[2];
}