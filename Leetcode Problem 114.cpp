// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

// Example 1:


// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]

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

void dfs(Node *root, vector<int> &result){
    if(!root) return;
    result.push_back(root->data);
    dfs(root->left, result);
    dfs(root->right, result);
}

vector<int> preOrder(Node *root){
    vector<int> result;
    dfs(root, result);
    return result;
}

Node* flatten(Node *root){
    if(!root) return root;
    if(!root->left && !root->right) return root;

    vector<int> pre = preOrder(root);
    Node *temp = root;
    for(int i=1; i<pre.size(); i++){
        temp->right = new Node(pre[i]);
        temp->left = nullptr;
        temp = temp->right;
    }
    return root;
}

void preOrderDFS(Node *node){
    if(node == nullptr){
        return;
    }

    cout<<node->data<<" ";
    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

void printFlattened(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main(){
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(5);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->right = new Node(6);

    cout<<"PreOrder: ";
    preOrderDFS(root1);
    cout<<endl;

    Node* flattenedRoot1 = flatten(root1);
    cout<<"Flattened: ";
    printFlattened(flattenedRoot1);
    cout<<endl;

    return 0;
}