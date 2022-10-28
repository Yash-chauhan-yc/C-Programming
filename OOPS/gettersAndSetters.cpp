#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    float price;

public:
    int model_no;
    string name;

    void print()
    {
        cout << name << endl;
        cout << model_no << endl;
        cout << price << endl;
    }

    void setPrice(int x)
    {
        int msp = 1000;
        if (x < msp)
            price = msp;
        else
            price = x;
    }

    int getPrice()
    {
        return price;
    }

    float appyDiscount(float x)
    {
        return price * (1.0 - x);
    }
};

int main()
{
    Car C;
    C.name = "Yash";
    C.model_no = 100;

    // Cannot access as it is a private member
    // C.price = 100; 

    C.setPrice(100);
    C.print();
    cout << C.getPrice();
    return 0;
}