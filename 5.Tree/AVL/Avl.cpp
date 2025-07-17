#include <algorithm> 
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node {
public:
    int key;
    Node<T>* left;
    Node<T>* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(0) {}
};

template <typename T>
class AVLTree {
private:
    Node<T>* root;

    int get_height(Node<T>* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
    }

    int get_balance(Node<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return get_height(node->left) - get_height(node->right);
    }

    Node<T>* rotate_right(Node<T>* y) {
        Node<T>* x = y->left;
        Node<T>* z = x->right;

        x->right = y;
        y->left = z;

        y->height = max(get_height(y->left), get_height(y->right)) + 1;
        x->height = max(get_height(x->left), get_height(x->right)) + 1;

        return x;
    }

    Node<T>* rotate_left(Node<T>* x) {
        Node<T>* y = x->right;
        Node<T>* z = y->left;

        y->left = x;
        x->right = z;

        x->height = max(get_height(x->left), get_height(x->right)) + 1;
        y->height = max(get_height(y->left), get_height(y->right)) + 1;

        return y;
    }

    void inorder_traversal(Node<T>* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorder_traversal(node->left, result);
        result.push_back(node->key);
        inorder_traversal(node->right, result);
    }

    Node<T>* get_min_value_node(Node<T>* node) {
        Node<T>* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    Node<T>* insert(Node<T>* node, T data) {
        if (node == nullptr) {
            return new Node<T>(data);
        }

        if (data < node->key) {
            node->left = insert(node->left, data);
        } 
        else if (data > node->key) {
            node->right = insert(node->right, data);
        } 
        else {
            return node; // Equal keys are not allowed in BST
        }

        node->height = 1 + max(get_height(node->left), get_height(node->right));

        int balance = get_balance(node);

        // Left Left Case
        if (balance > 1 && get_balance(node->left) >= 0) {
            return rotate_right(node);
        }

        // Left Right Case
        if (balance > 1 && get_balance(node->left) < 0) {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        // Right Right Case
        if (balance < -1 && get_balance(node->right) <= 0) {
            return rotate_left(node);
        }

        // Right Left Case
        if (balance < -1 && get_balance(node->right) > 0) {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    Node<T>* delete_node(Node<T>* root, int data) {
        if (root == nullptr) {
            return root;
        }
        
        if (data < root->key) {
            root->left = delete_node(root->left, data);
        } 
        else if (data > root->key) {
            root->right = delete_node(root->right, data);
        } 
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node<T>* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } 
                else {
                    *root = *temp;
                }
                delete temp;
            } 
            else {
                Node<T>* temp = get_min_value_node(root->right);
                root->key = temp->key;
                root->right = delete_node(root->right, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        root->height = 1 + max(get_height(root->left), get_height(root->right));

        int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0) {
        return rotate_right(root);
    }

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0) {
        return rotate_left(root);
    }

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

        return root;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(T data) {
        root = insert(root, data);
    }

    void delete_node(T data) {
        root = delete_node(root, data);
    }

    vector<int> inorder_traversal() {
        vector<int> result;
        inorder_traversal(root, result);
        return result;
    }
};

int main() {
    AVLTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    vector<int> traversal_result = tree.inorder_traversal();
    for (int key : traversal_result) {
        cout << key << " ";
    }
    cout << endl;

    tree.delete_node(4);

    traversal_result = tree.inorder_traversal();
    for (int key : traversal_result) {
        cout << key << " ";
    }
    cout << endl;

    return 0;
}