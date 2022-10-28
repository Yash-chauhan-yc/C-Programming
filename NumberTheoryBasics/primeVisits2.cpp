#include <iostream>
using namespace std;

void primeSeive(int *prime)
{

    for (long long int i = 2; i <= 100000; i++)
    {
        prime[i] = 1;
    }
    for (long long int i = 2; i <= 100000; i++)
    {
        if (prime[i] == 1)
        {
            for (long long int j = i * i; j <= 100000; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    int p[100000];
    primeSeive(p);
	int t;
	cin >> t;
	while(t--)
	{
		int csum[100000] = {0};
		for (int i = 0; i < 100000; i++)
		{
			csum[i] = csum[i - 1] + p[i];
		}
		int a, b;
		cin >> a >> b;
		cout << csum[b] - csum[a - 1] << endl;
	}
    return 0;
}