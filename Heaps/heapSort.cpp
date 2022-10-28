#include <iostream>
#include <vector>
using namespace std;

void heapify(int idx, vector<int> &v, int size)
{
    int left = 2 * idx;
    int right = left + 1;

    int maxIdx = idx;
    int last = size - 1;

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
        heapify(maxIdx, v, size);
    }
}

void buildHeap(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(i, v, v.size());
    }
}

void print(vector<int> v)
{
    for(int i=1; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void heapSort(vector<int> &arr)
{
    buildHeap(arr);
    int n = arr.size();

    while (n > 1)
    {
        swap(arr[1], arr[n - 1]);
        n--;

        heapify(1, arr, n);
    }
}

int main()
{
    vector<int> v;
    v.push_back(-1);
    int n;
    cin >> n;

    int no;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        v.push_back(no);
    }

    heapSort(v);
    print(v);
    return 0;
}