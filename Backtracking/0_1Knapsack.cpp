#include <iostream>
#include <algorithm>
using namespace std;

int Knapsack(int N, int C, int *wt, int *prices)
{
    if (N == 0 || C == 0)
    {
        return 0;
    }

    int ans = 0;
    int exclude, include;
    exclude = include = 0;
    if (wt[N - 1] <= C)
    {
        include = prices[N - 1] + Knapsack(N - 1, C - wt[N - 1], wt, prices);
    }
    exclude = Knapsack(N - 1, C, wt, prices);

    ans = max(include, exclude);
    return ans;
}

int main()
{
    int wt[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};
    int N = 4;
    int C = 6;
    cout << Knapsack(N, C, wt, prices);
    return 0;
}