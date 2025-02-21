// Given a binary tree with the following rules:

// root.val == 0
// For any treeNode:
// If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

// Implement the FindElements class:

// FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
// bool find(int target) Returns true if the target value exists in the recovered binary tree.
 

// Example 1:


// Input
// ["FindElements","find","find"]
// [[[-1,null,-1]],[1],[2]]
// Output
// [null,false,true]
// Explanation
// FindElements findElements = new FindElements([-1,null,-1]); 
// findElements.find(1); // return False 
// findElements.find(2); // return True 
// Example 2:


// Input
// ["FindElements","find","find","find"]
// [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
// Output
// [null,true,true,false]
// Explanation
// FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
// findElements.find(1); // return True
// findElements.find(3); // return True
// findElements.find(5); // return False
// Example 3:


// Input
// ["FindElements","find","find","find","find"]
// [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
// Output
// [null,true,false,false,true]
// Explanation
// FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
// findElements.find(2); // return True
// findElements.find(3); // return False
// findElements.find(4); // return False
// findElements.find(5); // return True

#include<bits/stdc++.h>
using namespace std;

unordered_set<int> values;

class Node{
    public:
        int data;
        Node *left, *right;

        Node(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

void FindElements(Node *root){
    if(!root) return;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto [node, val] = q.front();
        q.pop();
        node->data = val;
        values.insert(val);

        if(node->left) q.push({node->left, 2*val+1});
        if(node->right) q.push({node->right, 2*val+2});
    }
}

bool find(int target){
    return values.count(target);
}

int main(){

    Node *root1 = new Node(-1);
    root1->left = nullptr;
    root1->right = new Node(-1);
    FindElements(root1);
    find(1) == 0 ? cout<<"false"<<endl : cout<<"true"<<endl; //false
    find(2) == 0 ? cout<<"false"<<endl : cout<<"true"<<endl; //true

    Node *root2 = new Node(-1);
    root2->left = new Node(-1);
    root2->left->left = new Node(-1);
    root2->left->right = new Node(-1);
    root2->right = new Node(-1);
    FindElements(root2);
    find(1) == 0 ? cout<<"false"<<endl : cout<<"true"<<endl; //true
    find(3) == 0 ? cout<<"false"<<endl : cout<<"true"<<endl; //true
    find(5) == 0 ? cout<<"false"<<endl : cout<<"true"<<endl; //false

    return 0;
}