#include <iostream>

using namespace std;

int main(){
    int x;

    cin >> x; //Getting rid of numCases
    while(cin >> x){
        cout << ((abs(((((x * 63) + 7492) * 5) - 498)) / 10) % 10) << endl;
    }

    return(0);
}