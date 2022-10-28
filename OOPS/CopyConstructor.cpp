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

    // Parameterized Constructor 
    Car(int p, int m, string n)
    {
        price = p;
        model_no = m;
        name = n;
    }

    // copy constructor
    Car (Car &x)
    {
        price = x.price;
        model_no = x.model_no;
        name = x.name;
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
    Car C(1000, 10, "BMW");
    Car D(C);
    cout << "CAR C" << endl;
    C.print();

    D.setPrice(11111);
    cout << endl << "CAR D" << endl;
    D.print();
    return 0;
}