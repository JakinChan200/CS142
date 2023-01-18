#include <iostream>
#include <vector>

using namespace std;

void printSequence(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl << endl;

}

int main(){
    int numNums;
    cin >> numNums;

    vector<int> nums(numNums);
    vector<int> sums(numNums);

    for(int i = 0; i < nums.size(); i++){
        cin >> nums[i];
    }

    sums = nums;

    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && sums[i] < sums[j] + nums[i]){
                sums[i] = sums[j] + nums[i];
            }
        }
    }
    signed int maxValue = -1;
    for(int i = 0; i < numNums; i++){
        if(sums[i] > maxValue)
            maxValue = sums[i];
    }
    
    cout << maxValue;
    return 0;
}