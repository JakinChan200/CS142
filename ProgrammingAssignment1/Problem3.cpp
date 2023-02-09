#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

struct curWord{
    int iStart = 0;
    int iEnd;
    int curCost = 0;
    bool done = false;
};

int removeEdges(vector<int> &prices, curWord &wordStruct, string word){
    return wordStruct.curCost + prices[word[wordStruct.iStart]-97] + prices[word[wordStruct.iEnd]-97];
}

void printDP(vector<vector<curWord>> &grid, string word){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j].curCost << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j].done){
                cout << 0 << " ";
            }else{
                cout << word.substr(grid[i][j].iStart, grid[i][j].iEnd+1) << " ";
            }
        }
        cout << endl;
    }
}

int findCost(vector<int> &prices, string &word){
    vector<vector<curWord>> grid(word.size()+1,  vector<curWord>(word.size()+1));
    int minCost = INT_MAX;
    grid[0][0].iEnd = word.size()-1;

    for(int i = 1; i < grid.size(); i++){
        //Making first row decrementing end
        grid[0][i].iEnd = grid[0][i-1].iEnd-1;
        grid[0][i].curCost = grid[0][i-1].curCost + prices[word[grid[0][i-1].iEnd]-97];

        //Making first column removing beginning 
        grid[i][0].iEnd = word.size()-1;
        grid[i][0].iStart = i;
        grid[i][0].curCost = grid[i-1][0].curCost + prices[word[grid[i-1][0].iStart]-97];
    }

    for(int i = 1; i < grid.size(); i++){
        for(int j = 1; j < grid[0].size(); j++){
            if(grid[i-1][j-1].done){
                grid[i][j].done = true;
                grid[i][j].curCost = grid[i-1][j-1].curCost;
                grid[i][j].iEnd = grid[i][j].iStart;
                continue;
            }

            if(word[grid[i-1][j-1].iEnd] == word[grid[i-1][j-1].iStart]){
                grid[i][j].iStart = grid[i-1][j-1].iStart+1;
                grid[i][j].iEnd = grid[i-1][j-1].iEnd-1;
                grid[i][j].curCost = grid[i-1][j-1].curCost;
                if(grid[i][j].iStart >= grid[i][j].iEnd){
                    grid[i][j].iEnd = grid[i][j].iStart;
                    grid[i][j].done = true;
                    minCost = min(minCost, grid[i][j].curCost);
                }
                continue;
            }

            int leftCost = grid[i][j-1].curCost + prices[word[grid[i][j-1].iEnd]-97];
            int rightCost = grid[i-1][j].curCost + prices[word[grid[i-1][j].iStart]-97];

            if(leftCost < rightCost){
                grid[i][j].curCost = leftCost;
                grid[i][j].iStart = grid[i][j-1].iStart;
                grid[i][j].iEnd = grid[i][j-1].iEnd-1;
            }else{
                grid[i][j].curCost = rightCost;
                grid[i][j].iStart = grid[i-1][j].iStart+1;
                grid[i][j].iEnd = grid[i-1][j].iEnd;
            }
        }
    }
    // int leftCost;
    // int rightCost;
    // for(int i = 1; i < grid.size(); i++){
    //     for(int j = 1; j < grid[0].size(); j++){
    //         if(i == 0 && j == 0) continue;

    //         if(grid[i][j-1].done){
    //             leftCost = grid[i][j-1].curCost;
    //             grid[i][j].done = true;
    //         }
    //         if(grid[i-1][j].done){
    //             leftCost = grid[i][j-1].curCost;
    //             grid[i][j].done = true;
    //         }

    //         if(grid[i][j-1].iEnd - grid[i][j-1].iStart <= 2){
                
    //         }

    //         if(word[grid[i][j-1].iStart] == word[grid[i][j-1].iEnd]){
                
    //         }
    //     }
    // }
    //printDP(grid, word);
    return minCost;
}

int main(){
    int length;
    int k;

    cin >> length >> k;

    vector<int> prices(k);

    for(int i = 0; i < k; i++){
        cin >> prices[i];    
    }

    string word;
    cin >> word;

    cout << findCost(prices, word);
    return 0;
}