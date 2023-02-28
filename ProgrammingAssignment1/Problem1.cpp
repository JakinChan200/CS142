#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct PathCount{
    int value;
    signed int pathLength = 1;
};

void printGrid(vector<vector<PathCount>> &grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j].value << " ";
        }
        cout << endl;
    }
}

int findPath(vector<vector<PathCount>> &grid, int row, int col){
    if(grid[row][col].pathLength!=1) 
        return grid[row][col].pathLength;
    
    int mx = 0;
    if(row > 0){
        if(grid[row-1][col].value < grid[row][col].value){
            mx = max(mx, findPath(grid, row-1, col));
        }
    }

    if(row < grid.size()-1){
        if(grid[row+1][col].value < grid[row][col].value){
            mx = max(mx, findPath(grid, row+1, col));
        }
    }

    if(col > 0){
        if(grid[row][col-1].value < grid[row][col].value){
            mx = max(mx, findPath(grid, row, col-1));
        }
    }

    if(col < grid[0].size()-1){
        if(grid[row][col+1].value < grid[row][col].value){
            mx = max(mx, findPath(grid, row, col+1));
        }
    }

    return grid[row][col].pathLength = mx + 1;
}

int main(){
    int row;
    int col;
    cin >> row >> col;

    vector<vector<PathCount>> grid;

    for(int i = 0; i < row; i++){
        vector<PathCount> tempRow;
        for(int j = 0; j < col; j++){
            PathCount tempCell;
            cin >> tempCell.value;
            tempRow.push_back(tempCell);
        }
        grid.push_back(tempRow);
    }

    int currentLongestPath = 0;
    for(int i = 0; i < row;  i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j].pathLength == 1)
                currentLongestPath = max(currentLongestPath, findPath(grid, i, j));
        }
    }

    cout << currentLongestPath;
    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// struct PathCount{
//     int value;
//     signed int pathLength = 1;
// };

// void printGrid(vector<vector<PathCount>> &grid){
//     for(int i = 0; i < grid.size(); i++){
//         for(int j = 0; j < grid[0].size(); j++){
//             cout << grid[i][j].value << " ";
//         }
//         cout << endl;
//     }
// }

// void findPath(vector<vector<PathCount>> &grid, int row, int col, int &currentMax){
//     int value = grid[row][col].value;
//     int pathLength = grid[row][col].pathLength;

//     currentMax = max(grid[row][col].pathLength, currentMax);

//     cout << row << " " << col << " " << value << " " << pathLength << endl;

//     if(row != 0){
//         if(grid[row-1][col].value > value && grid[row-1][col].pathLength <= pathLength){
//             grid[row-1][col].pathLength = grid[row][col].pathLength + 1;
//             findPath(grid, row-1, col, currentMax);
//         }
//     }

//     if(row != grid.size()-1){
//         if(grid[row+1][col].value > value && grid[row+1][col].pathLength <= pathLength){
//             grid[row+1][col].pathLength = grid[row][col].pathLength + 1;
//             findPath(grid, row+1, col, currentMax);
//         }
//     }

//     if(col != 0){
//         if(grid[row][col-1].value > value && grid[row][col-1].pathLength <= pathLength){
//             grid[row][col-1].pathLength = grid[row][col].pathLength + 1;
//             findPath(grid, row, col-1, currentMax);
//         }
//     }

//     if(col != grid[0].size()-1){
//         if(grid[row][col+1].value > value && grid[row][col+1].pathLength <= pathLength){
//             grid[row][col+1].pathLength = grid[row][col].pathLength + 1;
//             findPath(grid, row, col+1, currentMax);
//         }
//     }
// }

// int main(){
//     int row;
//     int col;
//     cin >> row >> col;

//     vector<vector<PathCount>> grid;

//     for(int i = 0; i < row; i++){
//         vector<PathCount> tempRow;
//         for(int j = 0; j < col; j++){
//             PathCount tempCell;
//             cin >> tempCell.value;
//             tempRow.push_back(tempCell);
//         }
//         grid.push_back(tempRow);
//     }

//     int currentLongestPath = 0;
//     for(int i = 0; i < row;  i++){
//         for(int j = 0; j < col; j++){
//             if(grid[i][j].pathLength == 1)
//                 findPath(grid, i, j, currentLongestPath);
//         }
//     }

//     //printGrid(grid);
//     cout << currentLongestPath;
//     return 0;
// }