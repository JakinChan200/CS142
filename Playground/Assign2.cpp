#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

void compute1 ( int n ) {
    cout << n << endl;
    int *a = new int [n];
    //vector<int> a(n);
    for ( int i =0; i <n ; i ++) a[i] = i;
    auto start = high_resolution_clock::now();
    for ( int i =0; i <n ; i ++) a[i] *= 10;
    auto stop = high_resolution_clock::now();
    cout << "Time: " << duration_cast<milliseconds>(stop - start).count() << " milliseconds" << endl;
}

void compute2 ( int n ) {
    int *a = new int [n];
    //vector<int> a(n);
    for ( int i =0; i <n ; i ++) a[i] = i;
    auto start = high_resolution_clock::now();
    for ( int i =0; i <n ; i ++) a [(( long long )i *93) %n ] *= 10;
    auto stop = high_resolution_clock::now();
    cout << "Time: " << duration_cast<milliseconds>(stop - start).count() << " milliseconds" << endl;
}
int main(){
    cout << "compute1 takes ";
    compute1(1000000000);
    cout << endl;

    cout << "compute2 takes ";
    compute2(1000000000);
    cout << endl;
    return 0;
}