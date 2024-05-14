#include "iostream"

using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
    virtual void draw() = 0;
    virtual Shape *clone() = 0;
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(int radius) { this->radius = radius; }
    Circle *clone() { return new Circle(*this); }
    void draw() { cout << "Circle with radius " << radius << endl; }
};

class Square : public Shape
{
private:
    int side;
public:
    Square(int side) { this->side = side; }
    Square *clone() { return new Square(*this); }
    void draw() { cout << "Square with side " << side << endl; }
};

int main()
{
    Shape *circlePrototype = new Circle(10);
    Shape *squarePrototype = new Square(20);

    Shape *circle1 = circlePrototype->clone();
    Shape *square1 = squarePrototype->clone();

    circle1->draw();
    square1->draw();

    delete circlePrototype;
    delete squarePrototype;
    delete circle1;
    delete square1;
}