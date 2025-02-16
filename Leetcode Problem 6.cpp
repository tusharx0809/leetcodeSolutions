// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"

#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows){
    if(numRows <= 1){
        return s;
    }
    vector<string> rows(numRows);
    int j=0, d=1;
    for(int i=0; i<s.length(); i++){
        rows[j] += s[i];
        if(j == numRows-1){
            d = -1;
        }else if(j == 0){
            d=1;
        }
        j += d;
    }
    string res = "";
    for(int i=0; i<numRows; i++){
        res += rows[i];
    }
    return res;
}

int main(){
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3; 
    string output1 = convert(s1, numRows1);
    cout<<output1<<endl; //PAHNAPLSIIGYIR

    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    string output2 = convert(s2, numRows2);
    cout<<output2<<endl; //PINALSIGYAHRPI

    return 0;
}