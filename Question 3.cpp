//Question 3 (a)
#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
};  

Node* add_node(Node* parent,int data){
  Node* NewNode= new Node;
    
    if(parent==NULL){
        NewNode->data=data;
        NewNode->left=NULL;
        NewNode->right=NULL;
          return NewNode;
    }
    
    if(data<parent->data)
    {  parent->left=add_node(parent->left,data);}
    if(data>parent->data)
     {  parent->right=add_node(parent->right,data);}
    return parent;

}


int main() {
   Node* Node=NULL;
Node= add_node(Node,5);
Node= add_node(Node,6);
Node= add_node(Node,3);

    std::cout<<"Root:"<<Node->data<<std::endl;
    std::cout<<"Left:"<<Node->left->data<<std::endl;
    std::cout<<"Right:"<<Node->right->data<<std::endl;
    return 0;
}

//Question 3 (b)
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

Node* find_min(Node* node) {
    if (node == NULL || node->left == NULL) return node;
    return find_min(node->left);
}

Node* delete_node(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
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

    std::cout << "In-order before deletion: ";
    inorder(root);
    std::cout << "\n";

    int key = 8;
    root = delete_node(root, key);

    std::cout << "In-order after deleting " << key << ": ";
    inorder(root);
    std::cout << "\n";

    return 0;
}

//Question 3 (c)
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

int max_depth(Node* root) {
    if (root == NULL) return -1;
    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);
    int depth;
    if (left_depth > right_depth)
        depth = left_depth + 1;
    else
        depth = right_depth + 1;
    return depth;
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

    std::cout << "Maximum Depth (in edges): " << max_depth(root) << "\n";
    return 0;
}

//Question 3 (d)
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

int min_depth(Node* root) {
    if (root == NULL) return -1;
    if (root->left == NULL && root->right == NULL) return 0;

    int left_depth = min_depth(root->left);
    int right_depth = min_depth(root->right);
    int depth;

    if (root->left == NULL)
        depth = right_depth + 1;
    else if (root->right == NULL)
        depth = left_depth + 1;
    else if (left_depth < right_depth)
        depth = left_depth + 1;
    else
        depth = right_depth + 1;

    return depth;
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

    std::cout << "Minimum Depth (in edges): " << min_depth(root) << "\n";
    return 0;
}
