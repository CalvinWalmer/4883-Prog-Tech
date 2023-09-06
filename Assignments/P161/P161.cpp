#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int x, xPrev, on, minimum, time;
    vector<int> list;    

    xPrev = 0;

    while(cin >> x){
        if(x == 0 && x + xPrev != 0){
            time = 0;
            for(int t = minimum; t <= 18000; t++){
                on = 0;
                for (int i = 0; i < list.size(); i++){
                    if (t % (2 * list.at(i)) < list.at(i) - 5){
                        on++;
                    }
                }
                if (on == list.size()) {
                    time = t;
                    break; 
                }
            }


            list.clear();
            minimum = 0;


            if (time == 0){
                cout << "Signals fail to synchronise in 5 hours" << endl;

            }else{
                    cout << setw(2) << setfill('0') << time / 3600 << ":"
                    << setw(2) << setfill('0') << (time % 3600) / 60 << ":"
                    << setw(2) << setfill('0') << time % 60 << endl;
            }
        }else{
            if(minimum == 0){minimum = x;}
            if(x < minimum){minimum = x;}
            list.push_back(x);
        }
        xPrev = x;
    };
    return(0);
}