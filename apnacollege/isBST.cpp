#include<bits/stdc++.h>
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

bool isBST(Node* root, int min, int max){
    //i.e NULL is a BST
    if(root == NULL) return true;

    // >= due to BST doesnt contain duplicates hence when duplicate comes make it false
   if(root->data >= max){
       return false;
   }

   if(root->data <= min){
       return false;
   }
   
   bool left = isBST(root->left, min, root->data);
   bool right = isBST(root->right, root->data, max);
  

    return left && right;

}

int main(){
//     2
//    / \
//   1   3

Node* root = new Node(2);
root->left = new Node(1);
root->right = new Node(2);

cout<<isBST(root, INT_MIN, INT_MAX)<<endl;

    return 0;
}