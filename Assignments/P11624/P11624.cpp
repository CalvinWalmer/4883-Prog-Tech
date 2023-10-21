#include <iostream>
#include <vector>
#include <utility>

using namespace std;


int SpreadBFS(vector<vector<char>> maze);



int main(){
    char x;
    int cases, rows, cols;
    int steps;


    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> rows;
        cin >> cols;

        vector<vector<char>> maze;
        maze.resize(rows);

        for(int j = 0; j < rows; j++){
            maze[j].resize(cols);
            for(int k = 0; k < cols; k++){
                cin >> maze[j][k];   
            }
        }


        steps = SpreadBFS(maze);
        if (steps == -1){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << steps << endl;
        }
    }

    return(0);
}

int SpreadBFS(vector<vector<char>> maze){
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    vector<pair<int, int>> newFs;
    vector<pair<int, int>> newJs;
    vector<pair<int, int>> Js;
    vector<pair<int, int>> Fs;
    bool movement;
    int c = 1;

    //Get initial positions for fire and joe
    for(int j = 0; j < maze.size(); j++){
        for(int k = 0; k < maze[0].size(); k++){
            if (maze[j][k] == 'F'){newFs.push_back(make_pair(j, k));}
            else if (maze[j][k] == 'J'){newJs.push_back(make_pair(j, k));}
        }
    }


    do{
        movement = false;
        
        newJs.shrink_to_fit();
        newFs.shrink_to_fit();
        Js = newJs;
        Fs = newFs;
        newJs.clear();
        newFs.clear();

        for(int i = 0; i < Fs.size(); i++){
            for (int j = 0; j < 4; j++){
                if (    Fs[i].first+dx[j] >= 0 && Fs[i].first+dx[j] <= maze.size() - 1 &&
                        Fs[i].second+dy[j] >= 0 && Fs[i].second+dy[j] <= maze[0].size() - 1){ //If spread square is in bounds
                    if (maze[Fs[i].first+dx[j]][Fs[i].second+dy[j]] == '.' || maze[Fs[i].first+dx[j]][Fs[i].second+dy[j]] == 'J'){
                        maze[Fs[i].first+dx[j]][Fs[i].second+dy[j]] = 'F';
                        newFs.push_back(make_pair(Fs[i].first+dx[j], Fs[i].second+dy[j]));
                    }
                }
            }
        } 

        for(int i = 0; i < Js.size(); i++){
            for (int j = 0; j < 4; j++){
                if (    Js[i].first+dx[j] >= 0 && Js[i].first+dx[j] <= maze.size() - 1 &&
                        Js[i].second+dy[j] >= 0 && Js[i].second+dy[j] <= maze[0].size() - 1){ //If spread square is in bounds
                    if (maze[Js[i].first+dx[j]][Js[i].second+dy[j]] == '.'){
                        maze[Js[i].first+dx[j]][Js[i].second+dy[j]] = 'J';
                        newJs.push_back(make_pair(Js[i].first+dx[j], Js[i].second+dy[j]));
                        movement = true;
                    }
                }else{ //If spread square is out of bounds.... ESCAPE!!! :)
                    return c;
                }
            }
        }

        c++;
    }while(movement);
    return -1; //Impossible

}