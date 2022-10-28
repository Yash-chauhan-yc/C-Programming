#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27] = {0};

    char ch;
    cin >> ch;

    // running a stream until '.' occurs
    while (ch != '.')
    {
        q.push(ch);
        freq[ch - 'a']++;
        while(!q.empty())
        {    
            int idx = q.front() - 'a';
            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << endl;
                break;
            }
        }    
        
        if(q.empty())
        {
            cout << "-1" << endl;
        }

        cin >> ch;
    }
    return 0;
}