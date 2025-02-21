// A binary tree is uni-valued if every node in the tree has the same value.

// Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

 

// Example 1:


// Input: root = [1,1,1,1,1,null,1]
// Output: true
// Example 2:


// Input: root = [2,2,2,5,2]
// Output: false

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int val){
            data = val;
            left = right = nullptr;
        }
};

void dfs(Node *root, unordered_set<int> &values){
    if(!root) return;
    values.insert(root->data);
    dfs(root->left, values);
    dfs(root->right, values);
}

unordered_set<int> getValues(Node *root){
    unordered_set<int> values;
    dfs(root, values);
    return values;
}

bool isUnivalTree(Node *root){
    unordered_set<int> values = getValues(root);
    return values.size() == 1;
}

int main(){
    Node *root1 = new Node(1);
    root1->left = new Node(1);
    root1->left->left = new Node(1);
    root1->left->right = new Node(1);
    root1->right = new Node(1);
    root1->right->right = new Node(1);

    isUnivalTree(root1) == 0 ? cout<<"false"<<endl : cout<<"true"<<endl; //true

    Node *root2 = new Node(2);
    root2->left = new Node(2);
    root2->left->left = new Node(5);
    root2->left->right = new Node(2);
    root2->right = new Node(2);

    isUnivalTree(root2) == 0 ? cout<<"false"<<endl : cout<<"true"<<endl; //false

    return 0;
}