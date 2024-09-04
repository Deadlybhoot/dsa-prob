#include<iostream>
#include<queue>
using namespace std;


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

void printLevelOrder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        Node* node = q.front();
        q.pop();
       
       if(node == NULL){//-->just fot to print new line
        cout<<endl;}


        //Agar node NULL nahi he to node print karenge , aur oos node ke left aur right ko bhi check karenge
        if(node != NULL){//This is Must condition always aPPLY because if NULL occured then segmentation fault will give you Node->left mule
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);

        }

        //Agar hamare node NULL he aur queue empty nahi he to hum queue mein push karenge NULL
        else if(!q.empty())
            q.push(NULL);
   
    }
}
int main(){
Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);

printLevelOrder(root);

    return 0;
}
