#include <iostream>
#include <string>
#include <ranges>

template <class T>
T add(T a, T b)
{
    return a + b;
}

template <class T>
T add(std::string a, std::string b)
{
    return atof(a.c_str()) + atof(b.c_str());
}

template <typename T>
bool equal(T a, T b)
{
    return a == b;
}

template <>
bool equal<double>(double a, double b)
{
    return abs(a - b) < 0.0001;
}

int main()
{
    std::cout << add(1, 5) << std::endl;           // 6 – type deduced
    std::cout << add(1.6, 4.4) << std::endl;       // 6 – type deduced
    std::cout << add<int>("1", "5") << std::endl;  // 6 – type specified + specialization
    std::cout << add<double>(1.5, 1) << std::endl; // 2 – type specified

    float a = 0;
    for (int i = 0; i < 10; i++)
    {
        a += 0.1;
    }

    std::cout << std::boolalpha << equal(1, 1) << std::endl;                        // TRUE – type deduced
    std::cout << std::boolalpha << equal(static_cast<double>(a), 1.0) << std::endl; // TRUE – type deduced + specialization
    std::cout << std::boolalpha << equal<float>(a, 1) << std::endl;                 // FALSE – type specified + not specialized for float (floating point comparison!)
    return 0;
}