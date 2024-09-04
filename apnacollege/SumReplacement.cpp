#include<iostream>
using namespace std;

class Node
{   public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void SumReplacement(Node* &root){
    if(root == NULL){
        return;
    }

    SumReplacement(root->left);
    SumReplacement(root->right);

    if(root->left != NULL){
        root->data += root->left->data;
    }

    if(root->right != NULL){
        root->data += root->right->data;
    }


}

void preorder01(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder01(root->left);
    preorder01(root->right);
}


int main()
{

//      1
//     / \
//    2   3
//   /\  / \
//  4  5 6  7

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder01(root);
    SumReplacement(root);
    cout<<endl;
    preorder01(root);


    
    return 0;
}