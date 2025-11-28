#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int findIndex(int inorder[], int n, int data){
    for(int i=0;i<n;i++){
        if(inorder[i]==data)
            return i;
    }
    return -1;
}

Node* build(Node* root, int inorder[], int preorder[], int n, int &preIndex, int start, int end){
    if(start > end)
        return NULL;

    int value = preorder[preIndex];
    preIndex++;
    root = newNode(value);

    if(start == end)
        return root;

    int pos = findIndex(inorder, n, value);
    root->left = build(root->left, inorder, preorder, n, preIndex, start, pos-1);
    root->right = build(root->right, inorder, preorder, n, preIndex, pos+1, end);
    return root;
}

void inorderPrint(Node* root){
    if(root==NULL) return;
    inorderPrint(root->left);
    std::cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int inorder[]={4,2,5,1,6,3};
    int preorder[]={1,2,4,5,3,6};
    int n=6;
    int preIndex=0;
    Node* root=NULL;

    root = build(root,inorder,preorder,n,preIndex,0,n-1);

    std::cout<<"Inorder traversal of constructed tree: ";
    inorderPrint(root);
    std::cout<<std::endl;

    return 0;
}
