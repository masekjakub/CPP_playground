#include "iostream"

using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
    virtual void print() = 0;
};

class Circle : public Shape
{
public:
    Circle(string color) : color(color) {}
    void print() override
    {
        cout << "Circle: " << color << endl;
    }

private:
    string color;
};

class Square : public Shape
{
public:
    Square(string color) : color(color) {}
    void print() override
    {
        cout << "Square: " << color << endl;
    }

private:
    string color;
};

class ShapeFactory
{
public:
    virtual ~ShapeFactory() {}
    virtual Shape *createCircle() = 0;
    virtual Shape *createSquare() = 0;
};

class RedShapeFactory : public ShapeFactory
{
public:
    virtual Shape *createCircle() override
    {
        return new Circle("red");
    }
    virtual Shape *createSquare() override
    {
        return new Square("red");
    }
};

class BlackShapeFactory : public ShapeFactory
{
public:
    virtual Shape *createCircle() override
    {
        return new Circle("black");
    }
    virtual Shape *createSquare() override
    {
        return new Square("black");
    }
};

int main()
{
    Shape *shape = nullptr;
    ShapeFactory *factory = new RedShapeFactory();
    shape = factory->createCircle();
    shape->print();
    delete shape;
    
    shape = factory->createSquare();
    shape->print();
    delete shape;
    delete factory;

    factory = new BlackShapeFactory();
    shape = factory->createSquare();
    shape->print();
    delete shape;
    delete factory;
}