// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int, int> num_map;
    for(int i=0; i<nums.size(); i++){
        int comp = target - nums[i];
        if(num_map.find(comp) != num_map.end()){
            return {num_map[comp], i};
        }
        num_map[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    vector<int> res1 = twoSum(nums1, target1);
    vector<int> res2 = twoSum(nums2, target2);

    for(int i=0; i<res1.size(); i++){
        cout<<res1[i]<<" "; //0 1 
    }
    cout<<endl;
    for(int j=0; j<res2.size(); j++){
        cout<<res2[j]<<" "; //1 2
    }

    return 0;
}