#include <iostream>
using namespace std;

int factorial(int n)
{
    // 1. Base Case
    if (n == 0)
    {
        return 1;
    }

    // 2. Recurrence Relation / Recursive case
    // n! = n * (n-1)!
    // factorial(n) = n * factorial(n-1);
    // factorial(5) = n * factorial(4);
    // int smallerAnswer = factorial(n - 1); // 24

    // 3. Find the solution
    // int biggerAnswer = n * smallerAnswer; // 5*24=120

    return n * factorial(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}