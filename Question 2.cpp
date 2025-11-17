//Question 2 (a)
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

Node* search_recursive(Node* parent, int key) {
    if (parent == NULL || parent->data == key) return parent;
    if (key < parent->data) return search_recursive(parent->left, key);
    return search_recursive(parent->right, key);
}

Node* search_nonrecursive(Node* parent, int key) {
    Node* temp = parent;
    while (temp != NULL) {
        if (temp->data == key) return temp;
        if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

int main() {
    Node* root = NULL;
    root = add_node(root, 5);
    root = add_node(root, 6);
    root = add_node(root, 3);
    root = add_node(root, 4);
    root = add_node(root, 2);

    int key = 4;
    Node* r1 = search_recursive(root, key);
    Node* r2 = search_nonrecursive(root, key);

    std::cout << "Recursive Search: ";
    if (r1) std::cout << "Found " << r1->data << "\n"; 
    else std::cout << "Not Found\n";

    std::cout << "Non-Recursive Search: ";
    if (r2) std::cout << "Found " << r2->data << "\n"; 
    else std::cout << "Not Found\n";

    return 0;
}

//Question 2 (b)
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

Node* find_max(Node* parent) {
    if (parent == NULL || parent->right == NULL) return parent;
    return find_max(parent->right);
}

int main() {
    Node* root = NULL;
    root = add_node(root, 5);
    root = add_node(root, 6);
    root = add_node(root, 3);
    root = add_node(root, 7);
    root = add_node(root, 4);

    Node* maxNode = find_max(root);

    std::cout << "Maximum Element: ";
    if (maxNode) std::cout << maxNode->data << "\n"; 
    else std::cout << "Tree Empty\n";

    return 0;
}

//Question 2 (c)
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

Node* find_min(Node* parent) {
    if (parent == NULL || parent->left == NULL) return parent;
    return find_min(parent->left);
}

int main() {
    Node* root = NULL;
    root = add_node(root, 5);
    root = add_node(root, 6);
    root = add_node(root, 3);
    root = add_node(root, 7);
    root = add_node(root, 2);

    Node* minNode = find_min(root);

    std::cout << "Minimum Element: ";
    if (minNode) std::cout << minNode->data << "\n"; 
    else std::cout << "Tree Empty\n";

    return 0;
}

//Question 2 (d)
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

Node* find_min(Node* parent) {
    if (parent == NULL || parent->left == NULL) return parent;
    return find_min(parent->left);
}

Node* successor(Node* parent, int data) {
    Node* succ = NULL;
    Node* current = parent;
    while (current != NULL) {
        if (data < current->data) {
            succ = current;
            current = current->left;
        } 
        else if (data > current->data) {
            current = current->right;
        } 
        else {
            if (current->right != NULL)
                succ = find_min(current->right);
            break;
        }
    }
    return succ;
}

int main() {
    Node* root = NULL;
    root = add_node(root, 20);
    root = add_node(root, 8);
    root = add_node(root, 22);
    root = add_node(root, 4);
    root = add_node(root, 12);
    root = add_node(root, 10);
    root = add_node(root, 14);

    int key = 10;
    Node* succ = successor(root, key);

    std::cout << "In-order Successor of " << key << ": ";
    if (succ) std::cout << succ->data << "\n";
    else std::cout << "No Successor\n";

    return 0;
}

//Question 2 (e)
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

Node* find_max(Node* parent) {
    if (parent == NULL || parent->right == NULL) return parent;
    return find_max(parent->right);
}

Node* predecessor(Node* parent, int data) {
    Node* pred = NULL;
    Node* current = parent;
    while (current != NULL) {
        if (data > current->data) {
            pred = current;
            current = current->right;
        } 
        else if (data < current->data) {
            current = current->left;
        } 
        else {
            if (current->left != NULL)
                pred = find_max(current->left);
            break;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = add_node(root, 20);
    root = add_node(root, 8);
    root = add_node(root, 22);
    root = add_node(root, 4);
    root = add_node(root, 12);
    root = add_node(root, 10);
    root = add_node(root, 14);

    int key = 14;
    Node* pred = predecessor(root, key);

    std::cout << "In-order Predecessor of " << key << ": ";
    if (pred) std::cout << pred->data << "\n";
    else std::cout << "No Predecessor\n";

    return 0;
}
