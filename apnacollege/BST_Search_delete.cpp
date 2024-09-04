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

Node *insertInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (root->data < key)
    {
        root->right = insertInBST(root->right, key);
    }
    else
    {
        root->left = insertInBST(root->left, key);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* successor(Node* root){
    if(root == NULL){return NULL;}
    Node* ptr = root;
    while(ptr != NULL || ptr->left != NULL){
        ptr = ptr->left;
    }
    return ptr;
}

Node *DeleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < key)
    {
        root->right = DeleteNode(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = DeleteNode(root->left, key);
    }
    else
    { // Here less than ni nor greate thann our key i.e. find out...by upper two conditions
        if (root->left == NULL)
        { // root->left means the key which we have to find it's left = NULL;
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // case 3
            //==>he main he succesor root->right NOT root
            Node *temp = successor(root->right);        // 1)Find successor
            root->data = temp->data;                    // 2)replace node by successor
            root->right = DeleteNode(root->right, key); // 3)Delete a Node
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insertInBST(root, 1);
    insertInBST(root, 2);
    insertInBST(root, 3);
    insertInBST(root, 4);
    insertInBST(root, 5);
    insertInBST(root, 6);

    inorder(root);
    DeleteNode(root, 3);
    cout<<endl;
    inorder(root);
    

    return 0;
}