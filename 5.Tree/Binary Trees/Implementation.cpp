#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinaryTreeNode {
public:

    BinaryTreeNode(T val): data(val) {
        cout << "Node " << data << " was created\n";
    }

    void add_left_child(BinaryTreeNode<T>* node) {
        left = node;
        cout << "Node " << node->data << " was added as a left child of Node " << data << "\n";
    }

    void add_right_child(BinaryTreeNode<T>* node) {
        right = node;
        cout << "Node " << node->data << " was added as a right child of Node " << data << "\n";
    }

    T data;
    BinaryTreeNode<T>* left {nullptr};
    BinaryTreeNode<T>* right {nullptr};
};
    
template<typename T>
class BinaryTree {
public:
    BinaryTree(BinaryTreeNode<T>* tree_root = nullptr):  root(tree_root) {
        cout << "A tree was created\n";
    }

    BinaryTreeNode<T>* root;
};

int main() {

    // Create nodes
    BinaryTreeNode<string>* root_node = new BinaryTreeNode<string>("root");
    BinaryTreeNode<string>* left_node = new BinaryTreeNode<string>("left");
    BinaryTreeNode<string>* right_node = new BinaryTreeNode<string>("right");

    // Link nodes
    root_node->add_left_child(left_node);
    root_node->add_right_child(right_node);

    // Create binary tree
    BinaryTree<string> tree = BinaryTree<string>(root_node);

    return 0;
}