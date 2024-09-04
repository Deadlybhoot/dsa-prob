#include <bits/stdc++.h>
using namespace std;
//For printing vertical order of tree using hashmap;
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

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return;
    }
    mp[hd].push_back(root->data);
    getVerticalOrder(root->left, hd - 1, mp);
    getVerticalOrder(root->right, hd + 1, mp);
}

void printVerticalOrder(Node *root)
{
    int hd = 0;
    map<int, vector<int>> mp;

    getVerticalOrder(root, hd, mp);
    // map<int, vector<int>>::iterator it;

    // for (it = mp.begin(); it != mp.end(); it++)
    // {
    //     for (int i = 0; i < it->second.size(); i++)
    //     {
    //         cout << it->second[i] << " ";
    //     }
    //     cout << endl;
    // }

    //You forgot 
    for(auto it: mp){
        for(auto i: it.second){//Main use it.second
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    printVerticalOrder(root);

    return 0;
}