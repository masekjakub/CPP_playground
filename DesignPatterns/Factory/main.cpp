#include "iostream"

using namespace std;

class Shape
{
public:
    Shape() { cout << "Shape constructor" << endl; }
    virtual ~Shape() { cout << "Shape destructor" << endl; }
};

class ShapeFactory
{
public:
    virtual Shape *create() = 0;
    virtual ~ShapeFactory() {}
};

class Circle : public Shape
{
public:
    Circle() { cout << "Circle constructor" << endl; }
    ~Circle() { cout << "Circle destructor" << endl; }
};

class Square : public Shape
{
public:
    Square() { cout << "Square constructor" << endl; }
    ~Square() { cout << "Square destructor" << endl; }
};

class CircleFactory : public ShapeFactory
{
public:
    virtual Shape *create() override
    {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory
{
public:
    virtual Shape *create() override
    {
        return new Square();
    }
};

int main()
{
    ShapeFactory *factory = nullptr;
    char c;
    cout << "Enter c for circle or s for square: ";
    cin >> c;
    if (c == 'c')
    {
        factory = new CircleFactory();
    }
    else if (c == 's')
    {
        factory = new SquareFactory();
    }
    else
    {
        cout << "Invalid input" << endl;
        return 1;
    }

    Shape *shape = factory->create();
    delete shape;
}