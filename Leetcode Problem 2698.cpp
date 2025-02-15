//Punishment Number

//Given a positive integer n, return the punishment number of n.

// The punishment number of n is defined as the sum of the squares of all integers i such that:

// 1 <= i <= n
// The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
 

// Example 1:

// Input: n = 10
// Output: 182
// Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
// - 1 since 1 * 1 = 1
// - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
// - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
// Hence, the punishment number of 10 is 1 + 81 + 100 = 182

#include<bits/stdc++.h>
using namespace std;

bool isValidPart(string squ, int num, int index=0, int sum=0){
    if(index == squ.size()){
        return num==sum;
    }
    int curSum = 0;
    for(int i=index; i<squ.size(); i++){
        curSum = curSum * 10 + (squ[i] - '0');
        if(isValidPart(squ, num, i+1, sum+curSum)){
            return true;
        }
    }
    return false;
}

int punishmentNumber(int n){
    int punishment = 0;
    for(int i=1; i<=n; i++){
        int sq = i*i;
        string squ = to_string(sq);
        if(isValidPart(squ, i)){
            punishment += sq;
        }
    }
    return punishment;
}

int main(){
    vector<int> numbers = {10,12,37};
    vector<int> punishmentNumbers;

    for(int num: numbers){
        int punishmentNum = punishmentNumber(num);
        punishmentNumbers.push_back(punishmentNum);
    }

    for(int punishNum: punishmentNumbers){
        cout<<punishNum<<" "; //182 182 1478
    }

    return 0;
}
