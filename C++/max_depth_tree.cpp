/*


Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
 

*/

// code:

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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        

        int lheight = maxDepth(root->left);
        int rheight = maxDepth(root->right);

        return max(lheight,rheight)+1;
    }
};

int main() {
    // Example 1: [3,9,20,null,null,15,7]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    Solution sol;
    cout << "Example 1 - Max Depth: " << sol.maxDepth(root1) << endl;
    
    // Example 2: [1,null,2]
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    
    cout << "Example 2 - Max Depth: " << sol.maxDepth(root2) << endl;
    
    // Example 3: Empty tree
    TreeNode* root3 = nullptr;
    cout << "Example 3 - Max Depth: " << sol.maxDepth(root3) << endl;
    
    return 0;
}