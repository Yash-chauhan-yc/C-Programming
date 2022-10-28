#include<iostream>
#include<queue>
#include<string>
using namespace std;

class person
{
public:
    int age;
    string name;

    person()
    {
    }

    person(int a, string n)
    {
        age = a;
        name = n;
    }
};

class personCompare
{
public:
    bool operator()(person A, person B)
    {
        return A.age < B.age;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<person, vector<person>, personCompare> pq;

    for(int i=0; i<n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        person p(age, name);
        pq.push(p);
    }
    int k = 3;
    for(int i=0; i<k; i++)
    {
        person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }
    return 0;
}