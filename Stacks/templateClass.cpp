#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class stack
{
    private:
        vector<T> v;
    public:
        void push(T data)
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

        T top()
        {
            return v[v.size() - 1];
        }

};

int main()
{
    stack <char> v;   
    for(int i=65; i<=70; i++)
    {
        v.push(i);
    }
    while(!v.isEmpty())
    {
        cout << v.top() << endl;
        v.pop();
    }
    return 0;
}