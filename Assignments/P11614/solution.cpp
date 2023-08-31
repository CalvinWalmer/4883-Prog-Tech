#include <iostream>

using namespace std;

int main()
{
    int numNums;
    long long r, c;
    cin >> numNums;
    for(int i = 0; i < numNums; i++)
    {
        cin >> r;
        c = 1;
        do
        {
            r -= c;
            c++;
        }
        while(r >= 0);
        cout << c - 2 << endl;
    }
    return(0);
}
