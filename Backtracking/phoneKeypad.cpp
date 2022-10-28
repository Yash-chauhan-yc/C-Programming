#include <iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRs", "TUV", "WXYZ"};

void generateNumbers(char *input, char *output, int i, int j)
{
    if(input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    int digit = input[i] - '0';
    if(digit == 1 || digit ==0)
    {
        generateNumbers(input, output, i+1, j);
    }

    for(int k=0; keypad[digit][k]!='\0'; k++)
    {
        output[j] = keypad[digit][k];
        // fill the remaining par
        generateNumbers(input, output, i+1, j+1);
    }
    return;
}

int main()
{
    char input[100];
    cin >> input;
    char output[100];
    generateNumbers(input, output, 0, 0);
    return 0;
}