//Question 3 (a)
#include <iostream>
struct Tree {
    int val;
    Tree* lchild;
    Tree* rchild;
};

Tree* insertNode(Tree* root, int val) {
    Tree* t = new Tree;

    if (root == NULL) {
        t->val = val;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }

    if (val < root->val)
        root->lchild = insertNode(root->lchild, val);
    else if (val > root->val)
        root->rchild = insertNode(root->rchild, val);

    return root;
}

int main() {
    Tree* head = NULL;
    head = insertNode(head, 15);
    head = insertNode(head, 7);
    head = insertNode(head, 25);

    std::cout << "Root : " << head->val << std::endl;
    std::cout << "Left : " << head->lchild->val << std::endl;
    std::cout << "Right: " << head->rchild->val << std::endl;

    return 0;
}

//Question 3 (b)
#include <iostream>
struct Tree {
    int info;
    Tree* left;
    Tree* right;
};

Tree* add(Tree* root, int info) {
    if (root == NULL) {
        Tree* t = new Tree;
        t->info = info;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    if (info < root->info) root->left = add(root->left, info);
    else if (info > root->info) root->right = add(root->right, info);

    return root;
}

Tree* smallest(Tree* curr) {
    if (curr == NULL || curr->left == NULL) return curr;
    return smallest(curr->left);
}

Tree* removeNode(Tree* root, int key) {
    if (root == NULL) return root;

    if (key < root->info)
        root->left = removeNode(root->left, key);
    else if (key > root->info)
        root->right = removeNode(root->right, key);
    else {
        if (root->left == NULL) {
            Tree* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL) {
            Tree* tmp = root->left;
            delete root;
            return tmp;
        }

        Tree* tmp = smallest(root->right);
        root->info = tmp->info;
        root->right = removeNode(root->right, tmp->info);
    }
    return root;
}

void inorder(Tree* root) {
    if (root == NULL) return;
    inorder(root->left);
    std::cout << root->info << " ";
    inorder(root->right);
}

int main() {
    Tree* root = NULL;
    root = add(root, 50);
    root = add(root, 30);
    root = add(root, 70);
    root = add(root, 20);
    root = add(root, 40);
    root = add(root, 60);
    root = add(root, 80);

    std::cout << "In-order before deletion: ";
    inorder(root);
    std::cout << "\n";

    int key = 30;
    root = removeNode(root, key);

    std::cout << "In-order after deleting " << key << ": ";
    inorder(root);
    std::cout << "\n";

    return 0;
}

//Question 3 (c)
#include <iostream>
struct Tree {
    int val;
    Tree* left;
    Tree* right;
};

Tree* insert(Tree* root, int val) {
    if (root == NULL) {
        Tree* t = new Tree;
        t->val = val;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);

    return root;
}

int height(Tree* root) {
    if (root == NULL) return -1;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return (h1 > h2 ? h1 : h2) + 1;
}

int main() {
    Tree* root = NULL;
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);

    std::cout << "Maximum Depth: " << height(root) << "\n";

    return 0;
}

//Question 3 (d)
#include <iostream>
struct Tree {
    int val;
    Tree* left;
    Tree* right;
};

Tree* addNode(Tree* root, int val) {
    if (root == NULL) {
        Tree* t = new Tree;
        t->val = val;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    if (val < root->val) root->left = addNode(root->left, val);
    else if (val > root->val) root->right = addNode(root->right, val);

    return root;
}

int minDepth(Tree* root) {
    if (root == NULL) return -1;
    if (root->left == NULL && root->right == NULL) return 0;

    int leftd = minDepth(root->left);
    int rightd = minDepth(root->right);

    if (root->left == NULL) return rightd + 1;
    if (root->right == NULL) return leftd + 1;

    return (leftd < rightd ? leftd : rightd) + 1;
}

int main() {
    Tree* root = NULL;
    root = addNode(root, 100);
    root = addNode(root, 50);
    root = addNode(root, 150);
    root = addNode(root, 25);
    root = addNode(root, 75);

    std::cout << "Minimum Depth: " << minDepth(root) << "\n";

    return 0;
}
