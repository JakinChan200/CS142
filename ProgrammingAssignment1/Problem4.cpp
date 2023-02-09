#include <iostream>
#include <vector>

using namespace std;

int main(){
    int numNums;
    cin >> numNums;

    vector<int> nums(numNums);
    vector<int> iSums(numNums, 1);
    vector<int> dSums(numNums, 1);

    for(int i = 0; i < numNums; i++){
        cin >> nums[i];
    }

    //longest increasing sequence
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && iSums[i] < iSums[j] + 1){
                iSums[i] = iSums[j] + 1;
            }
        }
    }

    //longest decreasing sequence
    for(int i = nums.size()-2; i >= 0; i--){
        for(int j = nums.size()-1; j > i; j--){
            if(nums[i] > nums[j] && dSums[i] < dSums[j] + 1){
                dSums[i] = dSums[j] + 1;
            }
        }
    }

    signed int maxValue = -1;
    for(int i = 0; i < numNums; i++){
        maxValue = max(maxValue, iSums[i] + dSums[i] -1);
    }

    cout << maxValue;
    return 0;
}