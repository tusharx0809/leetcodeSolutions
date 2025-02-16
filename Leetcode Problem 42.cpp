// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> ans(n, 0);
    int maxHeight = 0;
    for(int i=n-1; i>=0; i--){
        if(maxHeight < height[i]){
            maxHeight = height[i];
        }
        ans[i] = maxHeight;
    }
    maxHeight = 0;
    int output = 0;
    for(int i=0; i<n; i++){
        if(maxHeight < height[i]){
            maxHeight = height[i];
        }
        output += min(maxHeight, ans[i])-height[i];
    }
    return output;
}

int main(){
    vector<int> heights1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int rainWater1 = trap(heights1);
    cout<<rainWater1<<endl; //6

    vector<int> heights2 = {4,2,0,3,2,5};
    int rainWater2 = trap(heights2);
    cout<<rainWater2<<endl; //9

    return 0;
}