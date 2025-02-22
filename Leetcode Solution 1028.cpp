// We run a preorder depth-first search (DFS) on the root of a binary tree.

// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

// If a node has only one child, that child is guaranteed to be the left child.

// Given the output traversal of this traversal, recover the tree and return its root.

 

// Example 1:


// Input: traversal = "1-2--3--4-5--6--7"
// Output: [1,2,5,3,4,6,7]
// Example 2:


// Input: traversal = "1-2--3---4-5--6---7"
// Output: [1,2,5,3,null,6,null,4,null,7]
// Example 3:


// Input: traversal = "1-401--349---90--88"
// Output: [1,401,null,349,88,90]

#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        int data;
        TreeNode *left, *right;
        TreeNode(int val){
            data = val;
            left = right = nullptr;
        }
};

TreeNode* recoverFromPreorder(string traversal){
    stack<TreeNode*> s;
    int index = 0;

    while(index < traversal.size()){
        int depth = 0;
        while(index < traversal.size() && traversal[index] == '-'){
            depth++;
            index++;
        }
        int valueStart = index;
        while(index < traversal.size() && isdigit(traversal[index])){
            index++;
        }
        int nodeVal = stoi(traversal.substr(valueStart, index-valueStart));
        TreeNode* newNode = new TreeNode(nodeVal);

        while(s.size() > depth){
            s.pop();
        }

        if(!s.empty()){
            if(!s.top()->left){
                s.top()->left = newNode;
            }else{
                s.top()->right = newNode;
            }
        }
        s.push(newNode);
    }
    while(s.size() > 1){
        s.pop();
    }
    return s.top();
}

void printPreOrder(TreeNode *root){
    if(!root) return;
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main(){
    string traversal1 = "1-2--3--4-5--6--7";
    string traversal2 = "1-2--3---4-5--6---7";
    string traversal3 = "1-401--349---90--88";

    TreeNode *root1 = recoverFromPreorder(traversal1);
    printPreOrder(root1); //1 2 3 4 5 6 7 
    cout<<endl;

    TreeNode *root2 = recoverFromPreorder(traversal2);
    printPreOrder(root2); //1 2 3 4 5 6 7
    cout<<endl;

    TreeNode *root3 = recoverFromPreorder(traversal3);
    printPreOrder(root3); //1 401 349 90 88
    cout<<endl;


    return 0;
}