#include<bits/stdc++.h> 
using namespace std; 
  
//   Aim:-Minimum Cost to cut a board into squares
  int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        int res = 0;
        
        sort(X.begin(), X.end(), greater<int>());
        sort(Y.begin(), Y.end(), greater<int>());
        
        int i =0;
        int j=0;
        int hr = 1, vr = 1;
        while(i<M-1 && j<N-1){//==>This i sreally important that you should use M-1 because M is the length Not index;
            if(X[i]>Y[j]){
                res += X[i] * vr;
                i++;
                hr++;
            }
            else{
                res += Y[j] * hr;
                j++;
                vr++;
            }
            
        }
        
        int totalSum = 0;
        while(i<M-1){
       
            res += X[i++] * vr;
                hr++;}
        
        // res += totalSum * vr;
        
        
        totalSum = 0;
        while(j<N-1){
           res += Y[j] * hr;
                j++;
                vr++;}
            
        // res += totalSum * hr;
        
        
        return res;
        
        
        
    }

        
void FlattenBt(Node* &root){
    if(root==NULL){
        return;
    }

    if(root->left){
    FlattenBt(root->left);
    Node*temp = root->right;
    root->right = root->left;
    root->left = NULL;
    
    Node*ptr = root->right;
    while(ptr->right != NULL){
        ptr = ptr->right;
    }
    ptr->right = temp;}

    FlattenBt(root->right);

}