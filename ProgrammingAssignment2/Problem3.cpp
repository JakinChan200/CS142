#include <bits/stdc++.h>

using namespace std;

struct node{
    int row;
    int col;
    int cost;
    bool operator<(const node &b) const{
        return cost > b.cost;
    }
};

// struct Compare {
//     bool operator()(node a, node b) {
//         return a.cost > b.cost;
//     }
// };

void printTable(vector<vector<int>> &table){
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[0].size(); j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int countTable(vector<vector<int>> &table){
    int counter = 0;
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[0].size(); j++){
            if(table[i][j] == 1){
                counter++;
            }
        }
    }
    counter++;
}

//signed int checkSets(vector<set<node>> &groups, node &cur){
//     for(int i = 0; i < groups.size(); i++){
//         if(groups[i].find(cur) != groups[i].end()){
//             return i;
//         }
//     }
//     return -1;
// }

// void combine(vector<vector<int>> &table, vector<set<node>> &groups, node &cheapest, int row, int col, int &runningCost){
//     int index = checkSets(groups, cheapest);
//     node temp2;
//     temp2.row = row;
//     temp2.cost = col;
//     temp2.cost = table[row][col];
//     int index2 = checkSets(groups, temp2);
//     if(!(index == index2)){
//         if(index2 != -1){
//             for(node element : groups[index2]){
//                 groups[index].insert(element);
//             }
//             groups[index2].clear();
//         }else{
//             groups[index].insert(temp2);
//         }
//         runningCost += cheapest.cost;
//     }
// }

// int findCost(vector<vector<int>> &table, priority_queue<node> &desks){
//     int runningCost = 0;
//     int counter = 0;
//     vector<set<node>> groups;

//     while(counter < table.size()*table[0].size()){
//         node cheapest = desks.top();
//         cout << "Node: " << cheapest.row << " " << cheapest.col << " " << cheapest.cost << endl;
//         desks.pop();

//         signed int index = checkSets(groups, cheapest);
//         cout << "index: " << index << endl;
//         if(index == -1){
//             set<node> temp;
//             temp.insert(cheapest);
//             groups.push_back(temp);
//             index = groups.size()-1;
//             for(node elements : groups[index]){
//                 cout << elements.row << " " << elements.col << " " << elements.cost << endl;
//             }
//         }else{
//             cout << "Set Size" << groups[index].size();
//             if(groups[index].size() >= table.size()*table[0].size()){
//                 return runningCost;
//             }
//         }
//         //cout << groups[0].size() << endl;
//         cout << runningCost << endl;

//         if(cheapest.row != 0){
//             combine(table, groups, cheapest, cheapest.row-1, cheapest.col, runningCost);
//             counter++;
//         }

//         if(cheapest.row != table.size()-1){
//             combine(table, groups, cheapest, cheapest.row+1, cheapest.col, runningCost);
//             counter++;
//         }

//         if(cheapest.col != 0){
//             combine(table, groups, cheapest, cheapest.row, cheapest.col-1, runningCost);
//             counter++;
//         }

//         if(cheapest.col != table[0].size()-1){
//             combine(table, groups, cheapest, cheapest.row, cheapest.col+1, runningCost);
//             counter++;
//         }

//         // for(int i = 0; i < groups.size(); i++){
//         //     cout << "i: " << i << endl;
//         //     for(node element : groups[i]){
//         //         cout << element.row << " " << element.col << " "<< endl;
//         //     }
//         // }
//     }
//     return runningCost;
// }

int findCost(vector<vector<int>> &table, priority_queue<node> &desks){
    unsigned int runningCost = 0;
    unsigned int counter = 0;
    vector<vector<int>> visited(table.size(), vector<int>(table[0].size(), 0));

    while(!desks.empty()){
        node cheapest = desks.top();
        cout << counter << endl;
        //cout << desks.size() << endl;
        //cout << cheapest.row << " " << cheapest.col << " " << cheapest.cost << endl;
        desks.pop();

        if(visited[cheapest.row][cheapest.col] == 0){
            visited[cheapest.row][cheapest.col] = 1;
            counter++;
        }

        if(cheapest.row != 0){
            if(visited[cheapest.row-1][cheapest.col] == 0){
                if(cheapest.cost < table[cheapest.row-1][cheapest.col]){
                    runningCost += cheapest.cost;
                    counter++;
                }
            }
        }

        if(cheapest.row != table.size()-1){
            if(visited[cheapest.row+1][cheapest.col] == 0){
                if(cheapest.cost < table[cheapest.row+1][cheapest.col]){
                    runningCost += cheapest.cost;
                    counter++;
                }
            }
        }

        if(cheapest.col != 0){
            if(visited[cheapest.row][cheapest.col-1] == 0){
                if(cheapest.cost < table[cheapest.row][cheapest.col-1]){
                    runningCost += cheapest.cost;
                    counter++;
                }
            }
        }

        if(cheapest.col != table[0].size()-1){
            if(visited[cheapest.row][cheapest.col+1] == 0){
                if(cheapest.cost < table[cheapest.row][cheapest.col+1]){
                    runningCost += cheapest.cost;
                    counter++;
                }
            }
        }

        //cout << "Total: " << runningCost << endl;
    }
    return runningCost;
}

int main(){
    int row;
    int col;

    cin >> row >> col;

    vector<vector<int>> table(row, vector<int>(col, 0));
    priority_queue<node> desks;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> table[i][j];
            node temp;
            temp.row = i;
            temp.col = j;
            temp.cost = table[i][j];
            desks.push(temp);
        }
    }

    //cout << desks.size() << endl;
    //printTable(table);
    cout << findCost(table, desks) << endl;


    return 0;
}