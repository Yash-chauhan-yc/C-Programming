#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    int price;

public:
    int model_no;
    char *name;

    Car()
    {
        name = NULL;
    }

    Car(int p, int m, char *n)
    {
        price = p;
        model_no = m;
        name = new char[strlen(n) + 1]; 
        strcpy(name, n);
    }

    
    Car(Car &x)
    {
        price = x.price;
        model_no = x.model_no;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
    }

    void print()
    {
        cout << name << endl;
        cout << model_no << endl;
        cout << price << endl;
    }

    void setPrice(int x)
    {
        price = x;
    }

    // we have call destructor for dynamically allocated memory
    ~Car()
    {
        cout << "Destroying Car name " << name << endl;
        if (name != NULL)
        {
            delete[] name;
        }
    }
};

int main()
{
    Car c(100000, 1, "BMW");
    Car d(c);
    Car e(100011, 14, "Maruti");
    c.print();
    cout << endl;
    d.print();
    return 0;
}