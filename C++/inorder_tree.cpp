

/*

94. Binary Tree Inorder Traversal
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
*/

// Cleaned version: single Solution + runnable main demonstrating inorder traversal
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node (LeetCode-style).
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

private:
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
};

int main() {
    // Build example tree: [1,2,3,4,5,null,8,null,null,6,7,9]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    Solution sol;
    vector<int> res = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (size_t i = 0; i < res.size(); ++i) {
        if (i) cout << ",";
        cout << res[i];
    }
    cout << '\n';

    return 0;
}
