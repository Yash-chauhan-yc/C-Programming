#include <iostream>
using namespace std;
int classAssignment(int n)
{
    // base case
    if (n == 1)
        return 2;

    if (n == 2)
        return 3;

    // recurive case
    return classAssignment(n - 1) + classAssignment(n - 2);
}
int main()
{
    int t;
    cin >> t;
    int n;
    int x = 1;
    while(t--)
    {   
        cin >> n;
        cout << "#" << x << " : " << classAssignment(n) << endl;
        x++;
    }
    return 0;
}