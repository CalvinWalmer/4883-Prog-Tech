#include <iostream>

using namespace std;

int main(){
    int at, next, numTests, numWalls, high, low;


    cin >> numTests;
    for(int i = 0; i < numTests; i++){
        high = 0;
        low = 0;
        cin >> numWalls;
        cin >> at;
        for(int j = 0; j < numWalls - 1; j++){
            cin >> next;
            if(next > at){
                high++;
            }else if (next < at){
                low++;
            }
            at = next;
        }

        cout << "Case " << i + 1 << ": " << high << " " << low << endl;
    }
    return(0);
}