#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> moves = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
void printBoard(vector<vector<int>> board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

unsigned int findMoves(vector<vector<int>> board, pair<int, int> cur, pair<int, int> end){
    queue<vector<pair<int, int>>> movesList;
    vector<pair<int, int>> current;
    current.push_back(cur);
    movesList.push(current);
    set<pair<int, int>> duplicates;
    duplicates.insert(cur);

    while(!movesList.empty()){
        current = movesList.front();
        if(current[current.size()-1] == end){
            // cout << "Final Moves: " << endl;
            // for(int i = 0; i < current.size(); i++){
            //     cout << current[i].first << " " << current[i].second << endl;
            // }
            return current.size()-1;
        }
        movesList.pop();

        for(int i = 0; i < moves.size(); i++){
            vector<pair<int, int>> temp = current;
            pair<int, int> tempPair;
            signed int tempFirst = temp[temp.size()-1].first + moves[i][0];
            signed int tempSecond = temp[temp.size()-1].second + moves[i][1];
            //cout << "Tempfirst: " << tempFirst << " TempSecond: " << tempSecond << endl; 

            if(tempFirst < 0 || tempFirst > 7){
                continue;
            }
            if(tempSecond < 0 || tempSecond > 7){
                continue;
            }
            if(board[tempFirst][tempSecond] == 1){
                continue;
            }
            int initSize = duplicates.size();
            tempPair = make_pair(tempFirst, tempSecond);
            duplicates.insert(tempPair);
            if(initSize == duplicates.size()){
                continue;
            }
            //cout << "Being Pushed: tempfirst: " << tempFirst << " TempSecond: " << tempSecond << endl; 

            temp.push_back(tempPair);
            movesList.push(temp);
        }
    }

    return -1;

    // for(int i = 0; i < movesList.front().size(); i++){
    //     cout << movesList.front()[i].first << " " << movesList.front()[i].second << endl;
    // }
    //return movesList.front().size();
}

int main(int argc, char* argv[]){
    int numPieces;
    string position;
    string start;
    string endString;
    string answer;
    int counter = 1;
    unsigned int numMoves;

    std::cin >> numPieces;
    while(numPieces != -1){
        vector<vector<int>> board(8, vector<int>(8, 0));
        pair<int, int> cur, end;
        for(int i = 0; i < numPieces; i++){
            std::cin >> position;
            board[position[1]-'1'][position[0]-'a'] = 1;
        }
        std::cin >> start;
        std::cin >> endString;

        cur = make_pair(start[1]-'1', start[0]-'a');
        end = make_pair(endString[1]-'1', endString[0]-'a');

        numMoves = findMoves(board, cur, end);
        answer += "Board " + to_string(counter) + ": " + (numMoves == -1 ? "not reachable\n" : to_string(numMoves) + " moves\n");
        counter++;
        //printBoard(board);
        std::cin >> numPieces;
    }
    cout << answer;

    return 0;
}