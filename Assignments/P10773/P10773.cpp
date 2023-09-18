#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    float to, d, v, u, temp;
    string end;

    cin >> to;

    for(int i = 0; i < to; i++){
        cin >> d;
        cin >> v;
        cin >> u;

        cout << "Case " << i + 1 << ": ";
        temp = (pow(u,2) - pow(v,2));
        if (temp > 0){
            temp = (d/sqrt(temp)) - (d / u);
            if (temp != 0){
                cout << fixed << setprecision(3) << temp << endl;
            }else{
                cout << "can't determine" << endl;
            }
        }else{
            cout << "can't determine" << endl;
        } 
    }
    return(0);
}