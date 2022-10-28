#include<iostream>
#include<vector>
using namespace std;

#define N 10000
vector<int> primes;
int p[N];

void Seive()
{
    for(int i=0; i<=N; i++)
    {
        p[i] = 1;
    }
    for(int i = 2; i<=N; i++)
    {
        if(p[i] == 1)
        {
            primes.push_back(i);
            for(int j=i*i; j<N; j+=i)
            {
                p[i] = 0;
            }
        }
    }
   
}

int main()
{
    Seive();
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;

        bool segment[100000];
        for(int i=0; i<n-m+1; i++)
        {
            segment[i] = 1;
        }
        for(auto x:primes)
        {
            if(x*x>N)
            {
                break;
            }
    
            int start = (m/x)*x;
             if(x>=m && x <=n)
            {
                start = x*2;
            }

            for(int i=start; i<N; i+=x)
            {
                segment[i-m] = 0;
            }
        }
        for(int i=0; i<N;i++)
        {
            if(segment[i-m] == 1)
            {
                cout << i << " ";
            }
        }
    }
    
    return 0;
}