#include <bits/stdc++.h>
using namespace std;

// To see Left & Right view of tree
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

void RightView(Node *root)
{   //When root comes NULL
    if(root==NULL){
    return;
}

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {   //Fakt for loop and q.size he vegl aal ahe baki sagl same ahe
         int n = q.size();
        for (int i = 1; i<= n; i++)//Ha for loop lavlya mule kay zal , level wise pop hot ahe & level wise parent che child push hotay
        {
            Node *temp = q.front();
                q.pop();
            if (temp != NULL)
            {   //JUst change i==n if you want to see right view
                if (i == 1)
                {
                    cout << temp->data << " ";//temp->data NOT root->data dhyan
                }

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }
    }
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

    RightView(root);
    return 0;
}