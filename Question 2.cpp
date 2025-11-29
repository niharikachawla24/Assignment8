//Question 2 (a)
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* leftChild;
    Node* rightChild;
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->val = val;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        return temp;
    }
    if (val < root->val) root->leftChild = insertNode(root->leftChild, val);
    else if (val > root->val) root->rightChild = insertNode(root->rightChild, val);
    return root;
}

Node* recursiveSearch(Node* root, int key) {
    if (root == NULL || root->val == key) return root;
    if (key < root->val) return recursiveSearch(root->leftChild, key);
    return recursiveSearch(root->rightChild, key);
}

Node* iterativeSearch(Node* root, int key) {
    Node* p = root;
    while (p != NULL) {
        if (p->val == key) return p;
        if (key < p->val) p = p->leftChild;
        else p = p->rightChild;
    }
    return NULL;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 9);
    root = insertNode(root, 20);
    root = insertNode(root, 7);
    root = insertNode(root, 11);

    int key = 11;
    Node* s1 = recursiveSearch(root, key);
    Node* s2 = iterativeSearch(root, key);

    cout << "Recursive Search: ";
    if (s1) cout << "Found " << s1->val << "\n";
    else cout << "Not Found\n";

    cout << "Non-Recursive Search: ";
    if (s2) cout << "Found " << s2->val << "\n";
    else cout << "Not Found\n";

    return 0;
}


//Question 2 (b)
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* leftChild;
    Node* rightChild;
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->val = val;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        return temp;
    }
    if (val < root->val) root->leftChild = insertNode(root->leftChild, val);
    else if (val > root->val) root->rightChild = insertNode(root->rightChild, val);
    return root;
}

Node* getMax(Node* root) {
    if (root == NULL || root->rightChild == NULL) return root;
    return getMax(root->rightChild);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 18);
    root = insertNode(root, 5);
    root = insertNode(root, 25);
    root = insertNode(root, 30);
    root = insertNode(root, 12);

    Node* mx = getMax(root);

    cout << "Maximum Element: ";
    if (mx) cout << mx->val << "\n";
    else cout << "Tree Empty\n";

    return 0;
}


//Question 2 (c)
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* leftChild;
    Node* rightChild;
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->val = val;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        return temp;
    }
    if (val < root->val) root->leftChild = insertNode(root->leftChild, val);
    else if (val > root->val) root->rightChild = insertNode(root->rightChild, val);
    return root;
}

Node* getMin(Node* root) {
    if (root == NULL || root->leftChild == NULL) return root;
    return getMin(root->leftChild);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 40);
    root = insertNode(root, 25);
    root = insertNode(root, 50);
    root = insertNode(root, 10);
    root = insertNode(root, 35);

    Node* mn = getMin(root);

    cout << "Minimum Element: ";
    if (mn) cout << mn->val << "\n";
    else cout << "Tree Empty\n";

    return 0;
}

//Question 2 (d)
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* leftChild;
    Node* rightChild;
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->val = val;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        return temp;
    }
    if (val < root->val) root->leftChild = insertNode(root->leftChild, val);
    else if (val > root->val) root->rightChild = insertNode(root->rightChild, val);
    return root;
}

Node* getMin(Node* root) {
    if (root == NULL || root->leftChild == NULL) return root;
    return getMin(root->leftChild);
}

Node* getSuccessor(Node* root, int key) {
    Node* succ = NULL;
    Node* curr = root;

    while (curr != NULL) {
        if (key < curr->val) {
            succ = curr;
            curr = curr->leftChild;
        }
        else if (key > curr->val) {
            curr = curr->rightChild;
        }
        else {
            if (curr->rightChild != NULL)
                succ = getMin(curr->rightChild);
            break;
        }
    }
    return succ;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    int key = 40;
    Node* succ = getSuccessor(root, key);

    cout << "In-order Successor of " << key << ": ";
    if (succ) cout << succ->val << "\n";
    else cout << "No Successor\n";

    return 0;
}

//Question 2 (e)
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* leftChild;
    Node* rightChild;
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->val = val;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        return temp;
    }
    if (val < root->val) root->leftChild = insertNode(root->leftChild, val);
    else if (val > root->val) root->rightChild = insertNode(root->rightChild, val);
    return root;
}

Node* getMax(Node* root) {
    if (root == NULL || root->rightChild == NULL) return root;
    return getMax(root->rightChild);
}

Node* getPredecessor(Node* root, int key) {
    Node* pred = NULL;
    Node* curr = root;

    while (curr != NULL) {
        if (key > curr->val) {
            pred = curr;
            curr = curr->rightChild;
        }
        else if (key < curr->val) {
            curr = curr->leftChild;
        }
        else {
            if (curr->leftChild != NULL)
                pred = getMax(curr->leftChild);
            break;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    int key = 60;
    Node* pred = getPredecessor(root, key);

    cout << "In-order Predecessor of " << key << ": ";
    if (pred) cout << pred->val << "\n";
    else cout << "No Predecessor\n";

    return 0;
}
