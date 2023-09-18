#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    float to, d, v, u;

    cin >> to;

    for(int i = 0; i < to; i++){
        cin >> d;
        cin >> v;
        cin >> u;


        cout << "Case " << i + 1 << ": " << fixed << setprecision(3) <<(d/sqrt(pow(u,2) - pow(v,2))) - (d / u) << endl;
    }



    return(0);
}