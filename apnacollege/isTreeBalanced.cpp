#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
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

bool isBalanced(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;
    if (isBalanced(root->left, &lh) == false)
    {
        return false;
    }

    if (isBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }

  
}
bool isCompleteBT(Node * root)
    {
        if (root == NULL)
        {
            return true;
        }

        if ((root->right != NULL) && (root->left != NULL))
        {
            return true;
        }
        else if ((root->right == NULL) && (root->left != NULL))
        {
            if ((root->left->left == NULL) && root->left->right == NULL)
            {
                return true;
            }
        }
        else
        {
            return false;
        }
      bool left = isCompleteBT(root->left);
        bool right = isCompleteBT(root->right);
        return left and right;
       
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
    // root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;

    if (isBalanced(root, &height) == true)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "UnBalanced" << endl;
    }

    cout<<isCompleteBT(root)<<endl;

    return 0;
}
