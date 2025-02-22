#include <iostream>
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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if ((root->data == n1) || (root->data == n2))
        return root;

    // Believe on recursion that he will give you output mg output bhetlyavr kay condition lihshin
    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);

    // jr lca bhetlach ni t NULL
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
    Node *lca = LCA(root, 6, 7);
    if (lca == NULL)
    {
        cout << "NOT Found" << endl;
    }
    else
    {
        cout << "LCA:- " << lca->data;
    }

    return 0;
}