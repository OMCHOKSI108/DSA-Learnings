/*

110. Balanced Binary Tree
Solved
Easy
Topics
premium lock icon
Companies
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104


*/

#include<iostream>
using namespace std;

class Solution{


public:
    bool isbalanced(TreeNode* root){
        return height(root)!=-1;
    }
private:
    int height(TreeNode* node){
        if(node==NULL) return 0;

        int leftHeight=height(node->left);
        if(leftHeight==-1) return -1;

        int rightHeight=height(node->right);
        if(rightHeight==-1) return -1;

        if(abs(leftHeight-rightHeight)>1) return -1;

        return max(leftHeight,rightHeight)+1;
    }


};


int main(){
 


    return 0;
}
Solution sol;
 
TreeNode* root1 = new TreeNode(3);
root1->left = new TreeNode(9);
root1->right = new TreeNode(20);
root1->right->left = new TreeNode(15);
root1->right->right = new TreeNode(7);
cout << "Test 1: " << (sol.isbalanced(root1) ? "true" : "false") << endl;
 
TreeNode* root2 = new TreeNode(1);
root2->left = new TreeNode(2);
root2->right = new TreeNode(2);
root2->left->left = new TreeNode(3);
root2->left->right = new TreeNode(3);
root2->left->left->left = new TreeNode(4);
root2->left->left->right = new TreeNode(4);
cout << "Test 2: " << (sol.isbalanced(root2) ? "true" : "false") << endl;

// Test case 3: Empty tree
TreeNode* root3 = nullptr;
cout << "Test 3: " << (sol.isbalanced(root3) ? "true" : "false") << endl;