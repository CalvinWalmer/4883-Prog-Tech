#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class State{
    public:

    State(int threshold){
        th = threshold;
        thsq = th * th;
    }
    

    void AddCity(int x, int y){
        cities.push_back(make_pair(x, y));
    }

    bool InState(int x, int y){
        for(int i = 0; i < cities.size(); i++){
            int dx = cities[i].first - x;
            int dy = cities[i].second - y;

            if((dx * dx) + (dy * dy) <= thsq){
                return(true);
            }
        }

        return(false);
    }

    void PrintCities(){
        for(int i = 0; i < cities.size(); i++){
            cout << cities[i].first << " " << cities[i].second << endl;
        }
    }

    private:
    vector<pair<int, int>> cities;
    int th, thsq;
};

    

int main(){
    int numCases = 0;
    cin >> numCases;

    for(int c = 0; c < numCases; c++){
        vector<State> states;
        int threshold, numLines;
        cin >> numLines;
        cin >> threshold;

        //Must be at least one state
        states.push_back(State(threshold));

        int x, y;
        cin >> x;
        cin >> y;
        states.back().AddCity(x, y);

        bool added;
        for(int i = 0; i < numLines - 1; i++){
            added = false;
            cin >> x;
            cin >> y;

            for(int j = 0; j < states.size(); j++){
                if (states[j].InState(x, y)){
                    states[j].AddCity(x, y);
                    added = true;
                }
            }

            if (!added){
                states.push_back(State(threshold));
                states.back().AddCity(x, y);
            }
        }

        // //Debug

        // for(int i = 0; i < states.size(); i++){
        //     cout << "STATE " << i + 1 << endl;
        //     states[i].PrintCities();
        // }
        // cout << "------------------------------" << endl;


        for(int i = 0; i < states.size(); i++){
            //Do MST within... Prims probably
            
        }


    }
    return(0);
}


//If two cities are within the same state, the get a road between them
//If two cities are in different states then they get a railroad between them

//Step 1: Determine States COMPLETE
//Step 2: Determine Roads in states
//Step 3: Determine Railroads between States