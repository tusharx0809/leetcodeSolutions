// You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.

// A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).

// Return the total number of good pairs.

 

// Example 1:

// Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1

// Output: 5

// Explanation:

// The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).
// Example 2:

// Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3

// Output: 2

// Explanation:

// The 2 good pairs are (3, 0) and (3, 1).

#include<bits/stdc++.h>
using namespace std;

int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k){
    unordered_map<int, int> freq;
    int pairs = 0;
    for(int num: nums2){
        freq[num*k]++;
    }
    for(int num: nums1){
        for(auto& [factor, count]: freq){
            if(num % factor == 0){
                pairs += count;
            }
        }
    }
    return pairs;
}

int main(){

    vector<vector<int>> testCase1 = {{1, 3, 4}, {1, 3, 4}};
    int k1 = 1;
    
    vector<vector<int>> testCase2 = {{1, 2, 4, 12}, {2, 4}};
    int k2 = 3;

    
    int pairsTestCase1 = numberOfPairs(testCase1[0], testCase1[1], k1);
    cout<<pairsTestCase1<<endl; //5

    int pairsTestCase2 = numberOfPairs(testCase2[0], testCase2[1], k2);
    cout<<pairsTestCase2<<endl; //2

    return 0;
}