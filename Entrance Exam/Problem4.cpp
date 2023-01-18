#include <vector>
#include <iostream>

using namespace std;


void printTree(vector<vector<int>> tree){
    for(int i = 0; i < tree.size(); i++){
        for(int j = 0; j < tree[i].size(); j++){
            cout << tree[i][j] << " ";
        }
        cout << endl;
    }
}

int countNodes(vector<vector<int>> &tree, int curNode, int curCount){
    if(tree[curNode][0] == 1){  //Current Node is a traitor, don't add it to the count
        return curCount;
    }else if(tree[curNode].size() == 1){    //Current Node has no children, add the current node to the count and return
        curCount++;
        return curCount;
    }

    int count = 1; //Include the current Node in the count
    for(int i = 1; i < tree[curNode].size(); i++){ //Iterate through children and recursively call this function
        count += countNodes(tree, tree[curNode][i], curCount);
    }
    return count;
}

int main(){
    int numFamilyMembers;
    int numTraitors;
    int curMember;

    cin >> numFamilyMembers >> numTraitors;

    vector<vector<int>> tree(numFamilyMembers, vector<int>(1, 0));

    for(int i = 1; i < numFamilyMembers; i++){
        cin >> curMember;
        tree[curMember].push_back(i);
    }

    int traitorIndex;
    for(int i = 0; i < numTraitors; i++){
        cin >> traitorIndex;
        tree[traitorIndex][0] = 1;
    }

    int maxCount = countNodes(tree, 0, 0);

    for(int i = 0; i < tree.size(); i++){
        if(tree[i][0] == 1){
            for(int j = 1; j < tree[i].size(); j++){
                int nodes = countNodes(tree, tree[i][j], 0);
                if(nodes > maxCount){
                    maxCount = nodes;
                }
            }
        }
    }

    // cout << endl;
    // printTree(tree);
    // cout << endl;

    cout << maxCount << endl;
    return 0;
}