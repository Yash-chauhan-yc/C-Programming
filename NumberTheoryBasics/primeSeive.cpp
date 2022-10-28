#include <iostream>
using namespace std;

void primeSeive(int n)
{
    // mark all number as prime
    int prime[10000];
    for(int i=2; i<n; i++)
    {
        prime[i] = 1;
    }

    // Seive
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 1)
            cout << i << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    primeSeive(n);

    return 0;
}