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

// In optimise way Diameter with STL pair by Love babbar
pair<int, int> calcDiameter03(Node *root)
{ // Here we taken pair as return type due to if condition returns  pair
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    }

    pair<int, int> lDiameter = calcDiameter03(root->left);
    pair<int, int> rDiameter = calcDiameter03(root->right);

    int lh = lDiameter.second;
    int rh = rDiameter.second;

    int lD = lDiameter.first;
    int rD = rDiameter.first;
    // we can assume to any one first or second we choosed second as height
    int currDiameter = lh + rh + 1;

    pair<int, int> ans;
    ans.second = max(lh, rh) + 1;
    ans.first = max(currDiameter, max(lD, rD));
    return ans;
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<< calcDiameter03(root).first<<endl;


    return 0;
}