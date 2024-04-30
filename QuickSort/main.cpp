#include "stdio.h"
#include "iostream"
#include "vector"
#include "random"

std::vector<int>::iterator partition(std::vector<int> &, std::vector<int>::iterator, std::vector<int>::iterator);
void qs(std::vector<int> &vec, std::vector<int>::iterator, std::vector<int>::iterator);
void printVector(std::vector<int>);

int main()
{
    //auto vec = std::vector{1,2,3,4};
    // auto vec = std::vector{4,3,2,1};
    auto vec = std::vector{5, 9, 7, 6, 1, 4, 3, 2, 0, 4};
    std::cout << "In:  ";
    printVector(vec);

    auto L = vec.begin();
    auto R = vec.end() - 1;
    qs(vec, L, R);

    std::cout << "Out: ";
    printVector(vec);
}

void qs(std::vector<int> &vec, std::vector<int>::iterator L, std::vector<int>::iterator R)
{
    if (std::distance(L, R) > 0)
    {
        std::vector<int>::iterator pivot = partition(vec, L, R);
        qs(vec, L, pivot - 1);
        qs(vec, pivot + 1, R);
    }
}

std::vector<int>::iterator partition(std::vector<int> &vec, std::vector<int>::iterator L, std::vector<int>::iterator R)
{
    std::iter_swap(L + std::rand() % std::distance(L, R), R); // swap pivot to right
    auto pos = L;

    for (auto cur = L; cur < R; cur++)
    {
        if (*cur < *R) // higher number on left -> swap
        {
            std::iter_swap(cur, pos);
            pos++;
        }
    }
    std::iter_swap(R, pos); // swap pivot to position
    return pos;
}

void printVector(std::vector<int> v)
{
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}