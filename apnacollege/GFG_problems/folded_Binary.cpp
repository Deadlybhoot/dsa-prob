#include<iostream>
using namespace std;

//Aim:- Learn How to make mirror image of tree & check Tree is Folded or Not;

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

void makeMirrorImage(Node* root){
        if(root==NULL){return;}
        
        makeMirrorImage(root->left);
        makeMirrorImage(root->right);
        
        Node* temp;
        
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        
    }

    //Here we just have to check wether pair of node are NULL or not;
bool isSame(Node* a, Node* b){
    if(a==NULL && b==NULL){return true;}
    
    //this are just to return false;
    if(a==NULL && b!=NULL){return false;}
    else if(a!= NULL && b==NULL){return false;}
    
   bool l = isSame(a->left, b->left);
    bool r = isSame(a->right, b->right);
    
    return l && r;
}


//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root)
{
    // Your code goes here
    if(root == NULL){return true;}
    
    makeMirrorImage(root->left);
    
    bool ans = isSame(root->left, root->right);
    
    return ans;
    
}


int main(){
        //     10
        //     / \
        //    7   15
        //   /      \
        //  9        11

Node* root = new Node(10);
root->left = new Node(7);
root->left->left = new Node(9);
root->right = new Node(15);
// root->right->right = new Node(11);

if( IsFoldable(root)){
    cout<<"Tree is foldable"<<endl;
}
else{
    cout<<"Not Foldable"<<endl;
}

    return 0;
}