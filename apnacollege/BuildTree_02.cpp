#include<iostream>
using namespace std;

//Algo
//TO build tree from postorder and inorder
// 1)Start from the last element of postorder because last node is the root node in postorder
// 2)Find that node in inorder 
// 3)First build right in postorder , attach "pos+1 to n" to right subtree
// 4)& attach "0 to pos-1" to left subtree

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


Node* BuildTree(int postOrder[], int inOrder[], int start , int end){
       //Base case
       if(start > end){
           return NULL;
       }
       
        static int idx = end;
        int curr = postOrder[idx];
        idx--;
        //Make node of currr
        Node* node = new Node(curr);

        //When Just one node in inOrder
        if(start==end){
            return node;
        }

        int pos = search(inOrder, start, end, curr);//===>Finding position of curr node inorder
        //This is the different step in Postorder first Build right subtree...
        node->right = BuildTree(postOrder, inOrder, pos+1, end);//===>attaching right part of inorder to curr node
        node->left = BuildTree(postOrder, inOrder, start, pos-1); //===>attach left part of inorder to cur node

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
int postOrder[] = {4, 2, 5, 3, 1};
int inOrder[] = {4, 2, 1, 5, 3};

Node* root = BuildTree(postOrder, inOrder, 0 , 4);//===>start =0,,,end == 4 Of inorder
inorder(root);


    return 0;
}