#include <iostream>
#include <vector>
#include <utility>


using namespace std;

bool Step(int dx, int dy, int &currRow, int &currCol, int &step, int &loopsFor, int &stepsFor, vector<vector<pair<char, int>>> &grid){
    if(currRow + dx < 0 || currRow + dx > grid.size()-1 || currCol + dy < 0 || currCol + dy > grid[0].size()-1){ //If outof bounds.. escape!
        //cout << "E" << endl;
        stepsFor = step + 1;
        return true;
    }else{
        if (grid[currRow + dx][currCol + dy].second > 0){ //If cell has been visited
        //cout << "V" << endl;
        loopsFor = step - grid[currRow + dx][currCol + dy].second + 1;
        if (step == loopsFor){
            stepsFor = 0;
        }else{
            stepsFor = grid[currRow + dx][currCol + dy].second;
        }

        return true;
        }else{ //If cell hasnt been visited
            //cout << "C" << endl;
            grid[currRow][currCol].second = step;
            step++;
            currRow += dx;
            currCol += dy;
        }
    }
    return false;
}


int main(){
    int rows, cols, entry, x;
    while(cin >> rows){
        cin >> cols;
        cin >> entry;

        if (rows == 0 && cols == 0 && entry == 0){
            return(0);
        }
        //Tuple: Direction, step visited
        vector<vector<pair<char, int>>> grid; 

        grid.resize(rows);

        for(int i = 0; i < rows; i++){
            grid[i].resize(cols);
            for(int j = 0; j < cols; j++){
                cin >> grid[i][j].first;
                grid[i][j].second = -1;
            }
        }
 
        bool finished = false;
        int currRow = 0; 
        int currCol = entry - 1;
        int step = 0;
        int loopsFor = 0, stepsFor = 0;
        while(!finished){
            switch(grid[currRow][currCol].first){
            case 'N':
                //cout << "N ";
                finished = Step(-1,0,currRow,currCol,step,loopsFor,stepsFor,grid);
                break;
            case 'S':
                //cout << "S";
                finished = Step(1,0,currRow,currCol,step,loopsFor,stepsFor,grid);
            break;
            case 'E':
                //cout << "E";
                finished = Step(0,1,currRow,currCol,step,loopsFor,stepsFor,grid);
            break;
            case 'W':
                //cout << "W";
                finished = Step(0,-1,currRow,currCol,step,loopsFor,stepsFor,grid);
            break;
            }
            //cout << currRow << " " << currCol << " " << step << " " << loopsFor << " " << stepsFor << endl;
        }

        if (loopsFor > 0){
            cout << stepsFor << " step(s) before a loop of " << loopsFor << " step(s)" << endl;
        }else{
            cout << stepsFor << " step(s) to exit" << endl;
        }
    }
    return(0);
}


