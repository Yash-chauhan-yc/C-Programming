#include<iostream>
#include"templateClass.h"
using namespace std;

int main()
{
    Vector<char> v;
    v.push_back(77);
    v.push_back(78);
    v.push_back(79);
    v.push_back(80);
    v.push_back(81);
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}