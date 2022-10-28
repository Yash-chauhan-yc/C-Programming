#include <iostream>
#include <stack>
using namespace std;

void playingCards(int arr[], int n)
{
    stack<int> a;
    stack<int> b;
    for(int i=0; i<n; i++)
    {   
        while(!a.empty())
        {
            if(a.top()%arr[i] == 0)
            {
                a.push(arr[i]);
            }
            else
            {
                b.push(arr[i]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[10000];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    playingCards
    return 0;
}