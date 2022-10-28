#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<int> l;

    // initialization
    list<int> l2{1, 2, 3, 4, 5, 6};

    // different data types
    list<string> l3{"apple", "grapes", "oranges", "mango", "banana"};

    // insert at end
    l3.push_back("kiwi");

    for (auto x : l3)
    {
        cout << x << "-->";
    }
    cout << endl;

    // reverse the list
    l3.reverse();

    // sort the list
    l3.sort();

    for (auto x : l3)
    {
        cout << x << "-->";
    }
    cout << endl;

    // remove from front
    cout << l3.front() << endl;
    l3.pop_front();

    // remove from back
    cout << l3.back() << endl;
    l3.pop_back();

    for (auto x : l3)
    {
        cout << x << "-->";
    }
    cout << endl;

    l3.push_back("guava");
    l3.push_back("guava");

    for (auto x : l3)
    {
        cout << x << "-->";
    }
    cout << endl;

    // remove the occurence from list
    string f;
    cin >> f;
    l3.remove(f);

    for (auto x : l3)
    {
        cout << x << "-->";
    }
    cout << endl;

    // remove the element from list
    auto it = l3.begin();
    it++;
    it++;
    l3.erase(it);

    for (auto x : l3)
    {
        cout << x << "-->";
    }

    /*for(auto it=l3.begin(); it!=l3.end(); it++)
    {
        cout << (*it) << "-->";
    }*/

    return 0;
}