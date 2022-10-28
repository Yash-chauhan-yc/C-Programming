#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int q;
    cin >> q;

    stack<int> s;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << s.top() << endl;
            s.pop();
            break;
        case 2:
            int prices;
            cin >> prices;
            s.push(prices);
            break;
        }
    }
    return 0;
}
