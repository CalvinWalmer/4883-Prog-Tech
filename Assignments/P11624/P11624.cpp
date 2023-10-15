#include <iostream>
#include <vector>

using namespace std;

int main(){
    char x;
    int cases, rows, cols;

    cin >> cases;

    for(int i = 0; i < cases; i++){
        cin >> rows;
        cin >> cols;
        
        vector<vector<int>> maze;
        maze.resize(rows);

        for(int j = 0; j < rows; j++){
            maze[j].resize(cols);
            for(int k = 0; k < cols; k++){
                cin >> maze[j][k];           
            }
        }

        for(int j = 0; j < rows; j++){
            for(int k = 0; k < cols; k++){
                cout << maze[j][k];           
            }
            cout << endl;
        }
        
    }

    return(0);
}