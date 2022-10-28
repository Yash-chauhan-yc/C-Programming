#include<iostream>
using namespace std;
int countSetBits(int n)
{
    int count = 0;
    while(n>0)
    {
        if((n&1)==1)
        count++;
        n = n>>1;
    }
    return count;

}
int main()
{
    int t;
    int n;
    cin >> t;
    while(t>0)
    {
        cin >> n;
        cout << countSetBits(n) << endl;
        t--;
    }
    return 0;
}