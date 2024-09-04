#include<bits/stdc++.h>
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

//This is found by Me..
int CountNodes01(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    CountNodes01(root->left);
    CountNodes01(root->right);
    sum++;//==>this will incrementing for each nodes
    return sum;
}

//THis is the Method of Apna collge
int CountNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return CountNodes(root->left) + CountNodes(root->right) + 1;
}

int SumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return SumOfNodes(root->left) + SumOfNodes(root->right) + root->data;
}

int calcHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight, rHeight) + 1;

}
//O(n^2)
int calcDiameter03(Node* root){
    if(root == NULL){
        return 0;
    }
    int Lh1 = calcHeight(root->left);
    int Rh2 = calcHeight(root->right);
    int currDiameter = Lh1 + Rh2 + 1;//===>Add 1 only when want via root node

    int lDiameter = calcDiameter03(root->left);
    int rDiameter = calcDiameter03(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));


}

//Optimise way madhi HEight sudhha ekach FUnction madhi calculate karavi lagte
//You do know how to implemment height function just do steps
int calcDiameter02(Node* root, int* height){//here we taken the pointer of height to avoid 
  if(root == NULL){
     *height = 0;
      return 0;
  }

    int lh = 0 , rh = 0;
    int lDiameter = calcDiameter02(root->left, &lh);
    int rDiameter  = calcDiameter02(root->right, &rh);
   
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;//he height function chi step ahe je ithe perform keli
    return max(currDiameter, max(lDiameter , rDiameter));

}
//======>THIS PAIR FUNCTION NOT WORKING HERE SEE IN DiameterWithPair.cpp file name..


// In optimise way Diameter with STL pair by Love babbar

// pair<int,int> calcDiameter03(Node* root){//Here we taken pair as return type due to if condition returns  pair
//     if(root == NULL){
//         pair<int, int> p = {0,0};
//         return p;
//     }
    
//     pair<int,int> lDiameter = calcDiameter03(root->left);
//     pair<int,int> rDiameter = calcDiameter03(root->right);

//     int lh = lDiameter.second;
//     int rh = rDiameter.second;

//     int lD = lDiameter.first;
//     int rD = rDiameter.first;
//     //we can assume to any one first or second we choosed second
//     int currDiameter = lh + rh + 1;

//     pair<int, int> ans;
//     ans.second =  max(lh, rh) + 1;
//     ans.first = max(currDiameter, max(lD, rD));
//     return ans;


// }





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
    // cout << CountNodes(root) << endl;
    // cout << SumOfNodes(root) << endl;
    // cout<<calcHeight(root)<<endl;
    // cout<<calcDiameter02(root)<<endl;
    // int height = 0;
    // cout<<calcDiameter01(root, &height)<<endl;
     cout<< calcDiameter03(root).first<<endl;


    return 0;
}