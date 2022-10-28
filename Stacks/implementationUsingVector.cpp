#include<iostream>
#include<vector>
using namespace std;

class stack
{
    private:
        vector<int> v;
    public:
        void push(int data)
        {
            v.push_back(data);
        }

        bool isEmpty()
        {
            return v.size() == 0;
        }

        void pop()
        {
            if(!isEmpty())
            {
                v.pop_back();
            }
        }

        int top()
        {
            return v[v.size() - 1];
        }

};

int main()
{
    stack v;   
    for(int i=1; i<=5; i++)
    {
        v.push(i*i);
    }
    while(!v.isEmpty())
    {
        cout << v.top() << endl;
        v.pop();
    }
    return 0;
}