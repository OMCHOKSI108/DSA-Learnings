/*
145. Binary Tree Postorder Traversal
Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};

        vector<int> ans;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
       ans.insert(ans.end(),left.begin(),left.end());
        
       ans.insert(ans.end(),right.begin(),right.end());
        ans.push_back(root->val);

        return ans;
    }
};

int main(){
     Solution sol;
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = sol.postorderTraversal(root);
    cout << "Preorder Traversal: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}