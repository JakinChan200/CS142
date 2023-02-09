#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

void printTree(vector<vector<int>> tree){
    for(int i = 0; i < tree.size(); i++){
        for(int j = 0; j < tree[i].size(); j++){
            cout << tree[i][j] << " ";
        }
        cout << endl;
    }
}

int treePath(vector<vector<int>> &tree, int node, signed int &curMax){
    if(tree[node].size() == 1)
        return tree[node][0];


    signed int max1 = INT_MIN;
    signed int max2 = INT_MIN;
    signed int tempMax;
    for(int i = 1; i < tree[node].size(); i++){
        tempMax = treePath(tree, tree[node][i], curMax);
        if(tempMax >= max1){
            max2 = max1;
            max1 = tempMax;
        }else{
            max2 = max(tempMax, max2);
        }
    }

    tempMax = tree[node][0];
    if(max1 > 0){
        tempMax += max1;
        if(max2 > 0) 
            tempMax += max2;
    }

    curMax = max(curMax, tempMax);
    if(max2 > 0){
        return tree[node][0] + max1;
    }
    return tempMax;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int numNodes;
    cin >> numNodes;

    vector<vector<int>> tree(numNodes, vector<int>(1, 0));

    for(int i = 0; i < numNodes; i++){
        cin >> tree[i][0];
    }

    int parent;
    for(int i = 1; i < numNodes; i++){
        cin >> parent;
        tree[parent].push_back(i);
    }

    signed int maxWeight = 0;
    treePath(tree, 0, maxWeight);

    cout << maxWeight;

    return 0;
}