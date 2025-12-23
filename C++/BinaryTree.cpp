#include<iostream>
using namespace std;

 vector<string> binaryTreepaths(TreeNode* root){
    vector<string> ans;
    if(root) findPath(root,ans,"");

    return ans;
}


void findPath(TreeNode* root,vector<string> ans,vector<string> temp){

    temp+=to_string(root->val);
    string left = findPath(root->left,ans,temp+"->");
    string right = findPath(root->right,ans,temp+"->");
    if(!root->left && !root->right) ans.push_back(temp); // leaf node 
}

int main(){
    TreeNode* root = {1,2,3,nullptr,5};
    vector<string> ans = binaryTreepaths(root);
    return 0;
}

