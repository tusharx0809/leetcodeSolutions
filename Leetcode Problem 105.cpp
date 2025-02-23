// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

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

int search(vector<int> &in, int val, int l, int r){
    for(int i=0; i<in.size(); i++){
        if(in[i] == val){
            return i;
        }
    }
    return -1;
}

Node *buildTreeRecur(vector<int> &in, vector<int> &pre, int &preIndex, int l, int r){
    if(l > r){
        return nullptr;
    }
    int rootVal = pre[preIndex];
    preIndex++;

    Node *root = new Node(rootVal);
    int index = search(in, rootVal, l, r);

    root->left = buildTreeRecur(in, pre, preIndex, l, index-1);
    root->right = buildTreeRecur(in, pre, preIndex, index+1, r);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder){
    int preIndex = 0;
    return buildTreeRecur(inorder, preorder, preIndex, 0, preorder.size()-1);
}

void inOrder(Node *root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Node *root = buildTree(preorder, inorder);

    inOrder(root); //9 3 15 20 7
    return 0;
}