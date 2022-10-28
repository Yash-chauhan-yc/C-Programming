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
        name = new char[strlen(n) + 1]; // because name is just a pointer pointing to a array of char in heap
        strcpy(name, n);
    }

    // Copy Assignment Constructor - deep copy
    Car operator=(Car &x)
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
};

int main()
{
    Car c(100000, 1, "BMW");
    Car d;
    d = c;  // assignment 

    d.name[0] = 'A'; // change to C and D both because it is dynamically allocated (shallow copy)........So we have to create Deep Copy
    d.setPrice(111111);      // only change to D

    c.print();
    cout << endl;
    d.print();
    return 0;
}