#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class BinaryTreeNode {
public:

    BinaryTreeNode(T data) : data(data) {}

    void add_left_child(BinaryTreeNode* node) {
        this->left = node;
    }

    void add_right_child(BinaryTreeNode* node) {
        this->right = node;
    }

    T data;
    BinaryTreeNode<T>* left {nullptr};
    BinaryTreeNode<T>* right {nullptr};
};

template<typename T>
class BinaryTree {
public:

    BinaryTree(BinaryTreeNode<T>* root_node) : root(root_node) {}

    void preorder_traversal(BinaryTreeNode<T>* node, vector<T>& traversal) {
        if (!node) {
            return;
        }
        // Visit the node
        traversal.push_back(node->data); 
        // Visit left subtree
        preorder_traversal(node->left, traversal); 
        // Visit right subtree
        preorder_traversal(node->right, traversal); 
    }

    void postorder_traversal(BinaryTreeNode<T>* node, vector<T>& traversal) {
        if (!node) {
            return;
        }
        // Visit left subtree
        postorder_traversal(node->left, traversal); 
        // Visit right subtree
        postorder_traversal(node->right, traversal); 
        // Visit the node
        traversal.push_back(node->data); 
    }

    void inorder_traversal(BinaryTreeNode<T>* node, vector<T>& traversal) {
        if (!node) {
            return;
        }
        // Visit left subtree
        inorder_traversal(node->left, traversal); 
        // Visit the node
        traversal.push_back(node->data); 
        // Visit right subtree
        inorder_traversal(node->right, traversal); 
    }

    BinaryTreeNode<T>* root;
};

int main() {
    BinaryTreeNode<char>* A = new BinaryTreeNode<char>('A');
    BinaryTreeNode<char>* B = new BinaryTreeNode<char>('B');
    BinaryTreeNode<char>* C = new BinaryTreeNode<char>('C');
    BinaryTreeNode<char>* D = new BinaryTreeNode<char>('D');
    BinaryTreeNode<char>* E = new BinaryTreeNode<char>('E');
    BinaryTreeNode<char>* F = new BinaryTreeNode<char>('F');

    A->add_left_child(B);
    A->add_right_child(C);
    B->add_left_child(D);
    B->add_right_child(E);
    C->add_left_child(F);

    BinaryTree<char> binary_tree(A);

    vector<char> preorder ;
    binary_tree.preorder_traversal(binary_tree.root, preorder);

    cout << "Preorder Traversal: ";
    for (char data : preorder) {
        cout << data << " ";
    }
    cout << endl;

    vector<char> postorder;
    binary_tree.postorder_traversal(binary_tree.root, postorder);
    cout << "Postorder Traversal: ";
    for (char data : postorder) {
        cout << data << " ";
    }
    cout << endl;

    vector<char> inorder;
    binary_tree.inorder_traversal(binary_tree.root, inorder);
    cout << "Inorder Traversal: ";
    for (char data : inorder) {
        cout << data << " ";
    }
    cout << endl;

    return 0;
}