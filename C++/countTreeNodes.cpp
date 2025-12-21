#include<iostream>
using namespace std;

class Solution{
public:
int CountNodes(TreeNode* root){
    if(root==nullptr){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}   



};

int main(){

    return 0;
}

TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

Solution sol;
cout << "Total nodes: " << sol.CountNodes(root) << endl;

return 0;