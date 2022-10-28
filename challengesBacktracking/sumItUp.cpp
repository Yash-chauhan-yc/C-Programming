#include <iostream>
#include <vector>
using namespace std;

void sumItUp(int a[], vector<int> result, int n, int sum, int target , int i)
{
    // base case
    if (sum == target)
    {
        
    }
    // inlude ith number
    sumItUp(a, result, n, sum+a[i], target, i+1);
    // ignore ith number
    sumItUp(a,result, n, sum, target, i+1);
    
}

int main()
{

    return 0;
}