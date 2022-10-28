#include <iostream>
#include <set>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 7, 1, 10};
    int n = 6;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (auto x : s)
    {
        cout << x << " ";
    }

    s.erase(10);
    cout << endl;

    for(auto x: s)
    {
        cout << x << " ";
    }

    return 0;
}