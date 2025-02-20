// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

// Example 1:

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.
// Example 2:

// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.
// Example 3:

// Input: nums = ["111","011","001"]
// Output: "101"
// Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct

#include<bits/stdc++.h>
using namespace std;

string findDifferentBinaryString(vector<string> &nums){
    for(int i=0; i<nums.size(); i++){
        nums[0][i] = nums[i][i] == '1' ? '0' : '1';
    }
    return nums[0];
}

int main(){

    vector<vector<string>> inputs = {{"01","10"},{"00","01"},{"111","011","001"}};

    vector<string> result;

    for(int i=0; i<inputs.size(); i++){
        string output = findDifferentBinaryString(inputs[i]);
        result.push_back(output);
    }

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }

    return 0;
}