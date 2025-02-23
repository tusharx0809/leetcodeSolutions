// Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

// If there exist multiple answers, you can return any of them.

 

// Example 1:


// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
// Example 2:

// Input: preorder = [1], postorder = [1]
// Output: [1]

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

Node *constructTreeUtil(vector<int> &pre, vector<int> &post, int &preIndex, int l, int h, int size){
    if(preIndex >= size || l > h){
        return nullptr;
    }
    Node *root = new Node(pre[preIndex]);
    preIndex++;

    if(l == h || preIndex >= size){
        return root;
    }

    int i=l;
    while(i <= h && post[i] != pre[preIndex]){
        i++;
    }

    if(i <= h){
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i+1, h-1, size);
    }
    return root;
}

Node *constructFromPrePost(vector<int> &preorder, vector<int> &postorder){
    int preIndex = 0;
    int size = preorder.size();
    return constructTreeUtil(preorder, postorder, preIndex, 0, size-1, size);
}
void inOrder(Node *root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    Node *root = constructFromPrePost(preorder, postorder);
    inOrder(root); //4 2 5 1 6 3 7
    return 0;
}