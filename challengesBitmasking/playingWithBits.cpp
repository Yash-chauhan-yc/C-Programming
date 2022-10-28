#include<iostream>
using namespace std;\

int countSetBitsBetweenAandB(int a, int b)
{
    int count = 0;
    for(int i=a; i<=b; i++)
    {
        int no = i;
        while(no > 0)
        {    
            if((no&1) == 1)
            {
                count++;
            }
            no = no >> 1;
        }
    }
    return count;
}

int main()
{
    cout << countSetBitsBetweenAandB(1,1);
    return 0;
}