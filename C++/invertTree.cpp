#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    TreeNode* invertTree(TreeNode* root){
        if(root == nullptr) return nullptr;
        
        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);
        
        root->left = r;
        root->right = l;
        
        return root;
    }
    
    void preorder(TreeNode* root){
        if(root == nullptr) return;
        
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
};

int main(){
    Solution sol;
    
    // Example: Create a simple tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    cout << "Original tree (preorder): ";
    sol.preorder(root);
    cout << "\n";
    
    root = sol.invertTree(root);
    
    cout << "Inverted tree (preorder): ";
    sol.preorder(root);
    cout << "\n";
    
    return 0;
}