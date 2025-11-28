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
        parent->left=add_node(parent->left,data);
    if(data>parent->data)
        parent->right=add_node(parent->right,data);
    return parent;
}

void bstToDLL(Node* root, Node* &head, Node* &prev){
    if(root==NULL) return;
    bstToDLL(root->left, head, prev);
    if(prev==NULL)
        head=root;
    else{
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    bstToDLL(root->right, head, prev);
}

Node* mergeDLL(Node* first, Node* second){
    if(!first) return second;
    if(!second) return first;
    Node* head=NULL;
    Node* tail=NULL;
    while(first && second){
        Node* temp=NULL;
        if(first->data < second->data){
            temp=first;
            first=first->right;
        } else {
            temp=second;
            second=second->right;
        }
        temp->left=tail;
        if(tail) tail->right=temp;
        else head=temp;
        tail=temp;
    }
    while(first){
        first->left=tail;
        if(tail) tail->right=first;
        else head=first;
        tail=first;
        first=first->right;
    }
    while(second){
        second->left=tail;
        if(tail) tail->right=second;
        else head=second;
        tail=second;
        second=second->right;
    }
    return head;
}

void printDLL(Node* head){
    Node* temp=head;
    while(temp){
        std::cout<<temp->data<<" ";
        temp=temp->right;
    }
    std::cout<<std::endl;
}

int main(){
    Node* Tree1=NULL;
    Node* Tree2=NULL;
    Tree1=add_node(Tree1,5);
    Tree1=add_node(Tree1,3);
    Tree1=add_node(Tree1,7);
    Tree2=add_node(Tree2,4);
    Tree2=add_node(Tree2,2);
    Tree2=add_node(Tree2,8);

    Node* head1=NULL; Node* prev1=NULL;
    Node* head2=NULL; Node* prev2=NULL;
    bstToDLL(Tree1,head1,prev1);
    bstToDLL(Tree2,head2,prev2);
    Node* merged=mergeDLL(head1,head2);

    std::cout<<"Merged Doubly Linked List in Sorted Order: ";
    printDLL(merged);
    return 0;
}
