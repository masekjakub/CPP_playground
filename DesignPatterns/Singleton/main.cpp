#include "iostream"
#include "cassert"

using namespace std;

class Singleton
{
public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static Singleton &getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return *instance;
    }

    static void destroyInstance()
    {
        if (instance)
        {
            delete instance;
            instance = nullptr;
        }
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

private:
    Singleton() {cout << "Singleton created" << endl;}
    ~Singleton() {cout << "Singleton destroyed" << endl;}
    static Singleton *instance;
    string name;
};

// Initialize the instance to nullptr
Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton& instance1 = Singleton::getInstance();
    Singleton& instance2 = Singleton::getInstance();
    assert(&instance1 == &instance2);

    instance1.setName("Singleton");
    cout << "Name: " << instance2.getName() << endl;

    instance1.destroyInstance();
    return 0;
}