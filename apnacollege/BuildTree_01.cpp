#include<iostream>
using namespace std;
//Algo
//TO build tree from preorder and inorder
// 1)Start from the first node of preorder because first node is the root node in preorder
// 2)Find that node in inorder 
// 3)when you found attach "0 to pos-1" to left subtree
// 4)"pos+1 to n" to right subtree
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

int search(int inOrder[], int start, int end, int curr){
    for(int i= start; i<=end; i++){
        if(inOrder[i] == curr){
            return i;
        }
    }
    return -1;
}


Node* BuildTree(int preOrder[], int inOrder[], int start , int end){
       //Base case
       if(start > end){
           return NULL;
       }
       
        static int idx = 0;
        int curr = preOrder[idx];
        idx++;
        //Make node of currr
        Node* node = new Node(curr);

        //When Just one node in inOrder
        if(start==end){
            return node;
        }

        int pos = search(inOrder, start, end, curr);//===>Finding position of curr node inorder
       
        node->left = BuildTree(preOrder, inOrder, start, pos-1); //===>attach left part of inorder to cur node
        node->right = BuildTree(preOrder, inOrder, pos+1, end);//===>attaching right part of inorder to curr node

        return node;

        

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
int preOrder[] = {1, 2, 4, 3, 5};
int inOrder[] = {4, 2, 1, 5, 3};

Node* root = BuildTree(preOrder, inOrder, 0 , 4);//===>start =0,,,end == 4 Of inorder
inorder(root);


    return 0;
}