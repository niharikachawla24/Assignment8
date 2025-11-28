#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = newNode(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "\nEnter number of nodes (including -1 for NULLs): ";
        cin >> n;

        int arr[n];
        cout << "Enter the values in level order (-1 for NULL): ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Node* root = buildTree(arr, n);
        cout << "Maximum Depth of this tree: " << maxDepth(root) << endl;
    }

    return 0;
}
