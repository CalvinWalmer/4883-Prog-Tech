#include <iostream>

using namespace std;

int main()
{
    int numNums;
    long long ps, n, check, nthTerm, l, h;
    cin >> numNums;

    for(int i = 0; i < numNums; i++)
    {
        cin >> ps;
        h = 1414213561;
        l = 0;
        n = h;

        while(true){
            nthTerm = (0.5 * n * (n+1));
            check = ps - nthTerm;
            //cout << "PS: " << ps << " N: " << n << " CHECK: " << check << endl;
            if (check >= 0 and check + nthTerm < (0.5 * (n+1) * (n+2))){
                cout << n << endl;
                break;
            }else if (check <= 0){ //n is too large
                h = n;
                n = ((h - l) / 2) + l;

            }else{ //n is too small
                l = n;
                n = h - ((h - l) / 2);
            }
        }
    }
    return(0);
}
