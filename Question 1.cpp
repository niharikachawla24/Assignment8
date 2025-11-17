#include <iostream>
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* add_node(Node* parent, int data) {
    if (parent == NULL) {
        Node* NewNode = new Node;
        NewNode->data = data;
        NewNode->left = NULL;
        NewNode->right = NULL;
        return NewNode;
    }
    if (data < parent->data) parent->left = add_node(parent->left, data);
    else if (data > parent->data) parent->right = add_node(parent->right, data);
    return parent;
}

void preorder(Node* parent) {
    if (parent == NULL) return;
    std::cout << parent->data << " ";
    preorder(parent->left);
    preorder(parent->right);
}

void inorder(Node* parent) {
    if (parent == NULL) return;
    inorder(parent->left);
    std::cout << parent->data << " ";
    inorder(parent->right);
}

void postorder(Node* parent) {
    if (parent == NULL) return;
    postorder(parent->left);
    postorder(parent->right);
    std::cout << parent->data << " ";
}

int main() {
    Node* root = NULL;
    root = add_node(root, 5);
    root = add_node(root, 6);
    root = add_node(root, 3);
    std::cout << "Pre-order: ";
    preorder(root);
    std::cout << "\nIn-order: ";
    inorder(root);
    std::cout << "\nPost-order: ";
    postorder(root);
    return 0;
}
