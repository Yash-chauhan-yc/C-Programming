#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /*int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
    }
    for (int x : v)
    {
        cout << x << ", ";
    }
    cout << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.max_size() << endl;*/

    vector<int> d{1, 2, 3, 4, 5};

    d.reserve(999);

    d.push_back(16);
    d.pop_back();

    d.insert(d.begin() + 3, 100);
    d.insert(d.begin() + 2, 4,50);

    d.erase(d.begin()+3);
    d.erase(d.begin()+3, d.begin()+4);

    cout << d.size() << endl;
    cout << d.capacity() << endl;

    for (int x : d)
        cout << x << ", ";
    
        
    return 0;
}