#include "stdio.h"
#include "iostream"

using namespace std;

class Car
{
public:
    virtual ~Car() { cout << "Car destructor" << endl; } // virtual destructor is needed to call the derived class destructor
    virtual void makeSound() {};

private:
};

class Formula : public Car
{
public:
    ~Formula() { cout << "Formula destructor" << endl; }
    virtual void makeSound() override { cout << "Smooooth operator" << endl; }
};

class FamilyCar : public Car
{
public:
    ~FamilyCar() { cout << "FamilyCar destructor" << endl; }
    virtual void makeSound() override { cout << "Brm" << endl; }
};

int main()
{
    Car *formula = new Formula();
    Car *familyCar = new FamilyCar();
    formula->makeSound();   // Formula declaration used
    familyCar->makeSound(); // FamilyCar declaration used
    delete formula;
    delete familyCar;
}