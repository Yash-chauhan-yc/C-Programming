#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

void decimalToBinary(int n)
{
    while (n > 0)
    {
        cout << (n % 2);
        n = n / 2;
    }
}

void reverseBinary(int n)
{
    decimalToBinary(n);
    cout << endl;
    int p = 1;
    int ans = 0;
    while (n > 0)
    {
        ans += (n % 2) * p;
        p *= 10;
        n /= 2;
    }
    cout << ans;
}
void decimalToBinaryThroughBitwise(int n)
{
    int ans = 0;
    int p = 1;
    while (n > 0)
    {
        ans += (n & 1) * p;
        p *= 10;
        n = n >> 1;
    }
    cout << ans;
}

void limitation(int n)
{
    string s;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            s.push_back('0');
        }
        else
        {
            s.push_back('1');
        }
        n /= 2;
    }
    reverse(s.begin(),s.end());
    cout << s;
}

void optimizedDecimalToBinary(int n)
{
    int mask = (1<<30);
    bool isOneFound = false;
    while(mask != 0)
    {
        if((mask&n)==0 && isOneFound == false)
        {
            mask = mask >>1;
            continue;
        }
        else
        {
            isOneFound = true;
            if((n&mask) > 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
            mask = mask >> 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    optimizedDecimalToBinary(n);
    return 0;
}