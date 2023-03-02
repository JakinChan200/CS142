#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(pair<int, double> a, pair<int, double> b){
        return a.second > b.second;
    }
};

void printGraphs(vector<vector<double>> graph){
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

double lowestCost(vector<vector<double>> &graph, vector<vector<double>> &edges, int start, int end){
    //treeTop<index, totalCost>
    priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> tree;
    tree.push(make_pair(start, 100.0));
    set<int> duplicates; //set of dupe indexes

    while(!tree.empty()){
        pair<int, double> treeTop = tree.top();
        tree.pop();

        int dupeSize = duplicates.size();
        duplicates.insert(treeTop.first);
        if(dupeSize == duplicates.size()){
            continue;
        }
 
        if(treeTop.first == end){
            break;
        }

        //Make pairs for all of the connections
        for(int i = 1; i < graph[treeTop.first].size(); i++){
            double tempCost = treeTop.second / (1.0-((int)edges[treeTop.first][i]/100.0));
            if(tempCost < graph[graph[treeTop.first][i]][0]){
                graph[graph[treeTop.first][i]][0] = tempCost;
                tree.push(make_pair(graph[treeTop.first][i], tempCost));
            }
        }
    }
    return graph[end][0];
}

int main(){
    int numFriends;
    int numPairs;

    cin >> numFriends;
    cin >> numPairs;

    vector<vector<double>> graph(numFriends, vector<double>(1, DBL_MAX));
    vector<vector<double>> edges(numFriends, vector<double>(1, 0.0));
    int firstFriend;
    int secondFriend;
    int cost;

    for(int i = 0; i < numFriends; i++){
        cin >> firstFriend;
        cin >> secondFriend;
        cin >> cost;
        firstFriend--;
        secondFriend--;
        graph[firstFriend].push_back(secondFriend);
        graph[secondFriend].push_back(firstFriend);
        edges[firstFriend].push_back(cost);
        edges[secondFriend].push_back(cost);
    }

    int start, end;

    cin >> start;
    cin >> end;

    std::cout << fixed << setprecision(9);
    double totalCost = lowestCost(graph, edges, end-1, start-1);
    cout << totalCost;
    // cout << "Graph" << endl;
    // printGraphs(graph);

    // cout << "Edges" << endl;
    // printGraphs(edges);
    return 0;
}