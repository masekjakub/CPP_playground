// https://www.geeksforgeeks.org/builder-pattern-c-design-patterns/

#include "iostream"

using namespace std;

class Car
{
public:
    string engine;
    string chassis;
    string suspention;

    void print()
    {
        cout << "Engine: " << this->engine << endl;
        cout << "Chassis: " << this->chassis << endl;
        cout << "Suspention: " << this->suspention << endl
             << endl;
    }
};

// Builder interface
class CarBuilder
{
public:
    virtual ~CarBuilder() {}
    virtual CarBuilder &setEngine(const string engine) = 0;
    virtual CarBuilder &setChassis(const string chassis) = 0;
    virtual CarBuilder &setSuspention(const string suspention) = 0;
    virtual Car getCar() = 0;
};

// Concrete builder
class SportCarBuilder : public CarBuilder
{
private:
    Car car;

public:
    SportCarBuilder()
    {
        car = Car();
    }

    SportCarBuilder &setEngine(const string engine) override
    {
        car.engine = engine;
        return *this;
    }

    SportCarBuilder &setChassis(const string chassis) override
    {
        car.chassis = chassis;
        return *this;
    }

    SportCarBuilder &setSuspention(const string suspention) override
    {
        car.suspention = suspention;
        return *this;
    }

    Car getCar() override
    {
        return car;
    }
};

// Director
class Mechanic
{
public:
    Car assembleVW(CarBuilder &builder)
    {
        return builder.setEngine("VW 2.0L")
            .setChassis("VW chassis")
            .setSuspention("Sport suspention")
            .getCar();
    }

    Car assembleFord(CarBuilder &builder)
    {
        return builder.setEngine("Ford 2.0L")
            .setChassis("Ford chassis")
            .setSuspention("Sport suspention")
            .getCar();
    }
};

int main()
{
    Mechanic mechanic;
    CarBuilder *carBuilder = new SportCarBuilder();

    Car car = mechanic.assembleVW(*carBuilder);
    car.print();

    car = mechanic.assembleFord(*carBuilder);
    car.print();

    delete carBuilder;
    return 0;
}