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

void rightView(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (i == size - 1)  // last node in this level (rightmost)
                cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
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
        cout << "Enter level order values (-1 for NULL): ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Node* root = buildTree(arr, n);
        cout << "Right View: ";
        rightView(root);
        cout << endl;
    }

    return 0;
}
