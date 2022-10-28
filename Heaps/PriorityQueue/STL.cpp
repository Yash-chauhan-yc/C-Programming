#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // decreasing order
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq1;
    int n;
    cin >> n;
    int no;
    for(int i=0; i<n; i++)
    {
        cin >> no;
        pq.push(no);
        pq1.push(no);
    }

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    while(!pq1.empty())
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }




    return 0;
}