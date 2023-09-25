#include <iostream>
#include <vector>

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
                // perform calc
                stack.clear();
                stack.push_back(read);
                trainSize = newTrainSize;
            }
    }
    return(0);
}

bool Calculate(vector<int> target){
    vector<int> a, station;
    for(int i = target.size(); i < 0; i--){
        station.push_back(i);
    }

    if(target.back() != a.back()){
        station.push_back(a.back());
        a.pop
    }
}