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

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL) return NULL;
    
    if((root->data == n1) || (root->data == n2)) return root;

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

 if ((leftLCA == NULL) && (rightLCA == NULL))
        return NULL;

    // It just a short form of !=NULL

    else if (leftLCA && rightLCA)
        return root;

    else if ((leftLCA != NULL) && (rightLCA == NULL))
        return leftLCA;
    else if ((rightLCA != NULL) && (rightLCA == NULL))
        return rightLCA;



}

int FindDist(Node* root, int n, int dist){
    if(root == NULL) return -1;

    if(root->data == n){
        return dist;
    }

    int leftdist = FindDist(root->left, n, dist + 1);
    if(leftdist != -1) return leftdist;
   
   int rightdist = FindDist(root->right, n, dist + 1);
   return rightdist;

    

}

int distBtwNodes(Node* root, int n1, int n2){
    Node *lca = LCA(root, n1, n2);

    int d1 = FindDist(lca, n1, 0);
    int d2 = FindDist(lca, n2, 0);

    return d1 + d2;
}
int main(){

//      1
//     / \
//    2   3
//   /\  / \
//  4  5 6  7
//          /
//          8
              

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
     root->right->right->left = new Node(8);

   cout<<distBtwNodes(root, 4, 6);



    return 0;
}