#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int trainSize, newTrainSize, prevRead, read, c;
    vector<int> stack;

    bool Calculate(vector<int>);

    cin >> trainSize;
    newTrainSize = trainSize;
    while(cin >> read){
            if (read == 0){
                cin >> newTrainSize;
                cin >> read;
            }

            if(stack.size() < trainSize){
                stack.push_back(read);
            }else{             
                if (Calculate(stack)){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }

                stack.clear();
                stack.push_back(read);
                if (trainSize != newTrainSize){
                    cout << endl;
                }
                trainSize = newTrainSize;
            }
    }
    return(0);
}

bool Calculate(vector<int> target){
    vector<int> a, station;
    // Reverse target so that we can pop from the back
    // Target will now be in the reverse order that it appears in input
    reverse(target.begin(), target.end());

    //load a with values
    for(int i = target.size(); i > 0; i--){
        a.push_back(i);
    }




    do{

        // cout << "A: ";
        //  for(int i = 0; i < a.size(); i++){
        //     cout << a.at(i) << " ";
        // }
        // cout << endl << "Station: ";
        //  for(int i = 0; i < station.size(); i++){
        //     cout << station.at(i) << " ";
        // }
        // cout << endl << "Target: ";
        //  for(int i = 0; i < target.size(); i++){
        //     cout << target.at(i) << " ";
        // }
        // cout << endl << endl;


        
        // If the car in A can be pushed directly to B
        if(!target.empty() && !a.empty() && target.back() == a.back()){
            target.pop_back();
            a.pop_back();
        // If the car is not in A but is in the station and can be pushed to B
        }else if(!target.empty() && !station.empty() && target.back() == station.back()){
            target.pop_back();
            station.pop_back();
        // Car is not available in A or the Station. Move a car from A to the station
        }else if (!a.empty()){
            station.push_back(a.back());
            a.pop_back();
        }else{
            station.pop_back(); //debug termination condition
        }
    }while(!a.empty() || !station.empty());

    // If target is empty then the operation was successful!
    return(target.empty());
}
