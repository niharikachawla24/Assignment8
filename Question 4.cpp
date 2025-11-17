#include <iostream>
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* new_node(int data) {
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int find_min(Node* root) {
    if (root == NULL) return 0;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int find_max(Node* root) {
    if (root == NULL) return 0;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

bool isBST(Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data <= min || root->data >= max) return false;
    if (!isBST(root->left, min, root->data)) return false;
    if (!isBST(root->right, root->data, max)) return false;
    return true;
}

bool check_BST(Node* root) {
    if (root == NULL) return true;
    int min = find_min(root);
    int max = find_max(root);
    return isBST(root, min - 1, max + 1);
}

int main() {
    Node* root = new_node(20);
    root->left = new_node(8);
    root->right = new_node(22);
    root->left->left = new_node(4);
    root->left->right = new_node(12);
    root->left->right->left = new_node(10);
    root->left->right->right = new_node(14);

    std::cout << "Inorder Traversal: ";
    inorder(root);
    std::cout << "\n";
    if (check_BST(root))
        std::cout << "Tree is a BST\n";
    else
        std::cout << "Tree is not a BST\n";

    root->left->right->left->data = 25;

    std::cout << "Inorder Traversal after change: ";
    inorder(root);
    std::cout << "\n";
    if (check_BST(root))
        std::cout << "Tree is a BST\n";
    else
        std::cout << "Tree is not a BST\n";

    return 0;
}
