#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    int price;

public:
    int model_no;
    string name;

    // Default Constructor
    Car()
    {
        cout << "Default Constructor" << endl;
    }

    // Paramterized Constructor
    Car(int p, int m, string n)
    {
        price = p;
        model_no = m;
        name = n;
    }

    void print()
    {
        cout << name << endl;
        cout << model_no << endl;
        cout << price << endl;
    }

    void setPrice(int p)
    {
        price = p;
    }

    int getPrice()
    {
        return price;
    }
};

int main()
{
    Car C(100, 12, "AUDI");

    /*  C.name = "BMW";
    C.model_no = 12;
    C.setPrice(1000);    */

    C.print();
    return 0;
}