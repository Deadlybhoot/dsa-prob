#include<bits/stdc++.h>

using namespace std;
struct Node
{
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

Node* BuildBST(int preorder[], int n, int* preorderIdx, int key, int min, int max){
  if(*preorderIdx > n){
      return NULL;
  }
    Node* root = NULL;//===>HA IDI DECLARE KELA karan return root karaycha hota , jar if chya scope madhe kela asta tr scope chya baher return root nahi karu shakla asta
    // int key = preorder[*preorderIdx];//==>He pay yethen pn lihu shakto pn yachya copies bante jayenge isiliye fuction ke sath pass kiya;
    
    if(key > min && key < max){
         root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

    
    
    if(*preorderIdx < n){
    root->left = BuildBST(preorder, n, preorderIdx, preorder[*preorderIdx], min, key);}
    if(*preorderIdx < n){
    root->right = BuildBST(preorder, n, preorderIdx, preorder[*preorderIdx], key, max);}

    }
    return root;
    
    
    
}

void preorder01(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder01(root->left);
    preorder01(root->right);
}




int main(){
int preorder[] = {10, 2, 1, 13, 11};
int n = 5;
int preorderIdx = 0;
Node* root = BuildBST(preorder, n, &preorderIdx,  preorder[0], INT_MIN, INT_MAX);//==>address pathvla karan nashan copies create zaLYA ASTYA

preorder01(root);



    return 0;
}