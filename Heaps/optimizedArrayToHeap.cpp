#include <iostream>
#include <vector>
using namespace std;

void heapify(int idx, vector<int> &v)
{
    int left = 2 * idx;
    int right = left + 1;

    int maxIdx = idx;
    int last = v.size() - 1;

    if(left <= last && v[left] > v[maxIdx])
    {
        maxIdx = left;
    }

    if(right <= last && v[right] > v[maxIdx])
    {
        maxIdx = right;
    }

    if(maxIdx != idx)
    {
        swap(v[maxIdx], v[idx]);
        heapify(maxIdx, v);
    }
}

void buildHeap(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(i, v);
    }
}

void print(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    buildHeap(v);
    print(v);
    return 0;
}