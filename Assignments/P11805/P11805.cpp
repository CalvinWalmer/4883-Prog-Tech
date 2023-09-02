#include <iostream>

using namespace std;

int main(){
    int numNums, n, k, p, end, offset;
    cin >> numNums;

    for(int i = 0; i < numNums; i++){
        cin >> n;
        cin >> k;
        cin >> p;


        if(p == n){offset = 0;} 
        else if(p < n){
            offset = n - (p % n);
        }
        else{
            offset = p - n;
        }

        cout << "Offset: " << offset << endl;

        if(k + offset > n)
        {
            cout << 1 + (k + offset - n) << endl;
        }else{
            cout << k + offset << endl;
        }
    }

    return(0);
}