#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<pair<int, int>> s;

    s.insert(make_pair(10, 50));
    s.insert(make_pair(50, 20));
    s.insert(make_pair(30, 10));
    s.insert(make_pair(60, 40));
    s.insert(make_pair(90, 90));
    s.insert(make_pair(100, 30));

    for (auto x : s)
    {
        cout << x.first << " and " << x.second << endl;
    }

    return 0;
}