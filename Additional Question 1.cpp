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

bool isLeaf(Node* node) {
    if (node == NULL) return false;
    if (node->left == NULL && node->right == NULL) return true;
    return false;
}

int sumOfLeftLeaves(Node* root) {
    if (root == NULL) return 0;
    int sum = 0;
    if (isLeaf(root->left))
        sum += root->left->data;
    else
        sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}

int main() {
    Node* root = new_node(3);
    root->left = new_node(9);
    root->right = new_node(20);
    root->right->left = new_node(15);
    root->right->right = new_node(7);

    std::cout << "Sum of Left Leaves: " << sumOfLeftLeaves(root) << "\n";
    return 0;
}
