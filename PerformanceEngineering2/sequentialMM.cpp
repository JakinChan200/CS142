//Two ways of sequentially running matrix multiplication
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void versionA(vector<vector<int>> &X, vector<vector<int>> &Y, vector<vector<int>> &Z, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                Z[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
}

void versionB(vector<vector<int>> &X, vector<vector<int>> &Y, vector<vector<int>> &Z, int n){
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                Z[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
}

int main(int argc, char* argv[]){

    int n = stoi(argv[1]);

    vector<vector<int>> X1(n, vector<int>(n, 0));
    vector<vector<int>> Y1(n, vector<int>(n, 0));
    vector<vector<int>> Z1(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            X1[i][j] = rand()%10;
            Y1[i][j] = rand()%10;
        }
    }

    vector<vector<int>> X2 = X1;
    vector<vector<int>> Y2 = Y1;
    vector<vector<int>> Z2 = Z1;

    auto start = high_resolution_clock::now();
    versionA(X1, Y1, Z1, n);
    auto stop = high_resolution_clock::now();
    cout << "Time for version A: " << duration_cast<milliseconds>(stop - start).count() << " milliseconds" << endl;

    start = high_resolution_clock::now();
    versionB(X2, Y2, Z2, n);
    stop = high_resolution_clock::now();
    cout << "Time for version B: " << duration_cast<milliseconds>(stop - start).count() << " milliseconds" << endl;

    return 0;
}