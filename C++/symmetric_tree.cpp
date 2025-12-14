/*
101. Symmetric Tree
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution{

public:
    bool isSymmetric(TreeNode* root){
        return isMirror(root->left,root->right);
    }

private:
    bool isMirror(TreeNode* t1,TreeNode* t2){
        if(t1==nullptr && t2==nullptr) return true;
        if(t1==nullptr || t2==nullptr) return false;
        return (t1->val==t2->val) && isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
    }

} 

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);
    cout << (result ? "True" : "False") << endl; // Output: True

    // Clean up memory (not shown)
    return 0;
}
