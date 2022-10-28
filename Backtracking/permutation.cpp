#include <algorithm>
#include <set>
#include <string>
#include <iostream>
using namespace std;


void Permutation1(char *input, int i)
{
    if (input[i] == '\0')
    {
        cout << input << ", ";
        return;
    }
    for (int j = i; input[j] != '\0'; j++)
    {
        swap(input[i], input[j]);
        Permutation1(input, i + 1);

        // Backtracking : Restore original array
        swap(input[i], input[j]);
    }
}

// for unique permutation for example aba
void Permutation2(char *input, int i, set<string> &s)
{
    if (input[i] == '\0')
    {
        // cout << input << ", ";
        string t(input);
        s.insert(t);
        return;
    }
    for (int j = i; input[j] != '\0'; j++)
    {
        swap(input[i], input[j]);
        Permutation2(input, i + 1, s);

        // Backtracking : Restore original array
        swap(input[i], input[j]);
    }
}

int main()
{
    char input[10];
    cin >> input;
    set<string> s;
    Permutation2(input, 0, s);

    //loop
    for(auto x:s)
    {
        cout << x << ","; 
    }
    return 0;
}