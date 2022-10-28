#include <iostream>
using namespace std;

int count = 0;
char table[][10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void generateNumbers(char *input, char *output, int i, int j)
{
    
    // base case
    if (input[i] == '\0')
    {
        count++;
        output[j] = '\0';
        cout << output << " ";
        return;
    }
    // recursive case
    char ch = input[i];
    int digit = ch - '0';
    if(digit == 0)
    {
        generateNumbers(input, output, i+1, j);
    }
    for (int k = 0; table[digit][k] != '\0'; k++)
    {

        output[j] = table[digit][k];
        generateNumbers(input, output, i+1, j+1);
    }
}

int main()
{
     char input[100];
    cin >> input;
    char output[100];
    generateNumbers(input, output, 0, 0);
    cout << endl <<  count;
    return 0;
}