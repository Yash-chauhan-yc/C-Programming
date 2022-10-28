#include <iostream>
using namespace std;

class Car
{
private:
public:
    float price;
    int model_no;
    char name[20];

    void print()
    {
        cout << price << endl;
        cout << model_no << endl;
        cout << name << endl;
    }

    float discount(float x)
    {
        return price * (1.0 - x);
    }
};

int main()
{
    Car c;
    Car d[20];
    cout << sizeof(c) << endl;
    ;
    cout << sizeof(d) << endl;

    c.price = 100;
    c.model_no = 1;
    c.name[0] = 'Y';
    c.name[1] = 'A';
    c.name[2] = 'S';
    c.name[3] = 'H';

    c.print();

    cout << "Enter the amount of discount you want to give : ";
    float discount;
    cin >> discount;
    cout << c.discount(discount);
    // cout << c.price << endl << c.model_no << endl <<  c.name << endl;
    return 0;
}