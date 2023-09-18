#include <iostream>

using namespace std;

int main(){
    int numNums, n, k, p, end, offset;
    cin >> numNums;

    for(int i = 1; i < numNums+1; i++){
        cin >> n;
        cin >> k;
        cin >> p;
        end = -1;

        if(p == n){
            end = k;
        }else{
            p = p % n;
            if (k + p <= n){
                end = k + p;
            }else{
                end = (p - (n - k)) % n;
            } 
        }
        cout << "Case "  << i << ": " << end << endl;
    }

    return(0);
}