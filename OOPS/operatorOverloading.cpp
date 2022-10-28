#include <iostream>
#include <string>
using namespace std;

class complex
{
private:
    int real;
    int img;

public:
    complex()
    {
        real = 0;
        img = 0;
    }

    // parameterized constructor
    complex(int r, int i)
    {
        real = r;
        img = i;
    }

    // copy constructor
    // It exists by default

    void setReal(const int r)
    {
        real = r;
    }

    void setImg(const int i)
    {
        img = i;
    }

    int getreal()
    {
        return real;
    }

    int getImg()
    {
        return img;
    }

    void print()
    {
        if (img > 0)
        {
            cout << real << " + " << img << "i" << endl;
        }
        else
        {
            cout << real << " - " << img << "i" << endl;
        }
    }

    void add(const complex &x)
    {
        real += x.real;
        img += x.img;
    }

    void operator+(complex &x)
    {
        real += x.real;
        img += x.img;
    }

    void operator!()
    {
        img *= -1;
    }

    int operator[](string s)
    {
        if (s == "real")
            return real;
        if (s == "img")
            return img;
    }
};

istream& operator>>(istream &is, complex &c)
{
    int r1, i1;
    cin >> r1 >> i1;
    c.setReal(r1);
    c.setImg(i1);
    return is;
}


ostream& operator<<(ostream& os, complex &c)
{
    c.print();
    return os;
}

int main()
{
    /*complex c1(3, 4);
    complex c2;
    c2.setReal(5);
    c2.setImg(8);

    c1.print();
    c2.print();

    // c1.add(c2);
    c1 + c2;
    c1.print();

    !c1;
    c1.print();

    cout << c2["img"]; */
    complex d, e;
    cin >> d >> e;
    cout << d <<  e;
    return 0;
}