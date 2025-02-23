// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
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
int search(vector<int> &arr, int s, int e, int val){
    int i;
    for(i = s; i <= e; i++){
        if(arr[i] == val){
            break;
        }
    }
    return i;
}

Node *buildUtil(vector<int> &in, vector<int> &post, int s, int e, int &pIndex){
    if(s > e){
        return nullptr;
    }
    Node *root = new Node(post[pIndex]);
    pIndex--;

    if(s == e){
        return root;
    }
    int iIndex = search(in, s, e, root->data);

    root->right = buildUtil(in, post, iIndex+1, e, pIndex);
    root->left = buildUtil(in, post, s, iIndex-1, pIndex);

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder){
    int n = inorder.size();
    int pIndex = n-1;
    return buildUtil(inorder, postorder, 0, n-1, pIndex);
}
void inOrder(Node *root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Node *root = buildTree(inorder, postorder);
    inOrder(root); //9 3 15 20 7
    return 0; 
}