#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int x, c, on, min, time;
    vector<int> list;    

    while(cin >> x){
        if(x == 0 && !c){
            c++;
            time = 0;
            for(int t = min; t < 18000; t++){
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
            min = 0;


            if (time == 0){
                cout << "Signals fail to synchronise in 5 hours" << endl;

            }else{
                   cout << setw(2) << setfill('0') << time / 3600 << ":"
                    << setw(2) << setfill('0') << (time % 3600) / 60 << ":"
                    << setw(2) << setfill('0') << time % 60 << endl;
            }
        }else{
            c = 0;
            if(min == 0){min = x;}
            if(x < min){min = x;}
            list.push_back(x);
        }
        
        if (c >= 3){
            break;
        }
    };
    return(0);
}