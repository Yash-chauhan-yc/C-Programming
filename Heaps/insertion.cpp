#include <iostream>
#include <vector>
using namespace std;

class heap
{
private:
    vector<int> v;
    bool minHeap;

    int compare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else
            return a > b;
    }

    void heapify(int idx)
    {
        int left = 2 * idx;
        int right = left + 1;

        int min_idx = idx;
        int last = v.size() - 1;

        if (left <= last && compare(v[left], v[min_idx]))
        {
            min_idx = left;
        }

        if (right <= last && compare(v[right], v[min_idx]))
        {
            min_idx = right;
        }

        if (min_idx != idx)
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;

        // keep pushing to the top till you reach a root node or stop midway becuase current element is already greater than parent (assuming it is a min heap)
        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{
    // give some init size and type-min/max heap

    // min heap
    heap h;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }

    // remove all elements one by one
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }

    heap h1(10, false);
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int no;
        cin >> no;
        h1.push(no);
    }

    // remove all elements one by one
    while (!h1.empty())
    {
        cout << h1.top() << " ";
        h1.pop();
    }

        return 0;
}