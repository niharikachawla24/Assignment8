#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* new_node(int data) {
    Node* n = new Node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

vector<Node*> generateTrees(int start, int end) {
    vector<Node*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++) {
        vector<Node*> left_trees = generateTrees(start, i - 1);
        vector<Node*> right_trees = generateTrees(i + 1, end);

        for (Node* left : left_trees) {
            for (Node* right : right_trees) {
                Node* root = new_node(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}

void preorder(Node* root) {
    if (root == NULL) {
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<Node*> all_trees = generateTrees(1, n);

    cout << "Total unique BSTs: " << all_trees.size() << "\n";
    for (int i = 0; i < all_trees.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        preorder(all_trees[i]);
        cout << "\n";
    }
    return 0;
}
