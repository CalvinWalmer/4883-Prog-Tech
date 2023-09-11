#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int x, xPrev, xPrevPrev, on, minimum, time;
    vector<int> list;    

    xPrev = 1;
    xPrevPrev = 1;
    minimum = 0;

    while(cin >> x){
        if(x == 0 && xPrev != 0 && xPrevPrev != 0){
            time = 0;
            for(int t = (2 * minimum) - 5; t <= 18000; t++){
                on = 0;
                for (int i = 0; i < list.size(); i++){
                    if (t % (2 * list.at(i)) < list.at(i) - 5){
                        on++;
                    }
                }
                if (on == list.size() && t > 0) {
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
            if(minimum == 0){
                minimum = x;
            }
            if(x < minimum){
                minimum = x;
            }
            list.push_back(x);
        }
        xPrevPrev = xPrev;
        xPrev = x;
    };
    return(0);
}