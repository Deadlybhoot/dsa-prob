#include<bits/stdc++.h>
using namespace std;
//Aim:- To Flatten a BT tree into linked list in preorder sequence
struct Node{
    int data;
    Node* left;
    Node* right;


    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void FlattenBt(Node* &root){
    if(root==NULL){
        return;
    }
     Node*prev = NULL;
    if(root->left){
    FlattenBt(root->left);
    Node*temp = root->right;
    root->right = root->left;
    prev = root->left;
    
    Node*ptr = root->right;
    while(ptr->right != NULL){
        ptr = ptr->right;
    }
    ptr->right = temp;}
    root = prev;

    FlattenBt(root->right);
        root = prev;

}


void printLL(Node* head){
    Node*ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr= ptr->right;
    }
    cout<<endl;
}

void preorder(Node*root){
    if(root == NULL){return;}

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



int main(){
        //     1
        //    / \
        //   2   3
        //  /\   /\
        // 7  6 4  5


        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(7);
        root->left->right = new Node(6);
        root->right->left = new Node(4);
        root->right->right = new Node(5);
        preorder(root);
            cout<<endl;
        FlattenBt(root);
        printLL(root);






    return 0;
}