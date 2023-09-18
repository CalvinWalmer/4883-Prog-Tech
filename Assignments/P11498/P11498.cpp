#include <iostream>

using namespace std;

int main(){
    int borderX, borderY, numCoords, x, y;

    while(cin >> numCoords){
        cin >> borderX;
        cin >> borderY;
        for(int i = 0; i < numCoords; i++){
            cin >> x;
            cin >> y;

            if(x == borderX || y == borderY){
                cout << "divisa";
            }else{
                if(y > borderY){
                    cout << 'N';
                }else{
                    cout << 'S';
                }

                if(x > borderX){
                    cout << 'E';
                }else{
                    cout << 'O';
                }
            }
            cout << endl;
        }
    }

    return(0);
}