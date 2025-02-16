// Given an integer n, find a sequence that satisfies all of the following:

// The integer 1 occurs once in the sequence.
// Each integer between 2 and n occurs twice in the sequence.
// For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
// The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

// Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

// A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

// Example 1:

// Input: n = 3
// Output: [3,1,2,3,2]
// Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
// Example 2:

// Input: n = 5
// Output: [5,3,1,4,3,5,2,4,2]

#include<bits/stdc++.h>
using namespace std;

bool backtrack(vector<int> &result, vector<bool> &used, int index, int n){
    if(index ==  result.size()) return true;

    if(result[index] != 0) return backtrack(result, used, index+1, n);

    for(int num=n; num>=1; num--){
        if(used[num]) continue;
        if(num == 1){
            result[index] = 1;
            used[num] = true;
            if(backtrack(result, used, index+1, n)) return true;
            result[index] = 0;
            used[num] = false;
        }else{
            if(index+num < result.size() && result[index+num] == 0){
                result[index] = result[index+num] = num;
                used[num] = true;

                if(backtrack(result, used, index+1, n)) return true;

                result[index] = result[index+num] = 0;
                used[num] = false;
            }
        }
    }
    return false;
}

vector<int> constructDistancedSequences(int n){
    vector<int> result((2*n)-1);
    vector<bool> used(n+1, false);

    backtrack(result, used, 0, n);
    return result;
}

int main(){
    vector<int> numbers = {3, 5, 7};
    vector<vector<int>> results;

    for(int num: numbers){
        results.push_back(constructDistancedSequences(num));
    }

    for(int i=0; i<results.size(); i++){
        cout<<numbers[i]<<": ";
        for(int j=0; j<results[i].size(); j++){
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }

    // 3: 3 1 2 3 2 
    // 5: 5 3 1 4 3 5 2 4 2
    // 7: 7 5 3 6 4 3 5 7 4 6 2 1 2

    return 0;
}