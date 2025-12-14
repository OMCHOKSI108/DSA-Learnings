//Bredth-First, Depth-First Traversal in Binary Tree 

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void depthFirstTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        depthFirstTraversal(node->left);
        depthFirstTraversal(node->right);
    }

};
int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "Depth-First Traversal: ";
    tree.depthFirstTraversal(tree.root);
    cout << endl;
    

    return 0;
}
