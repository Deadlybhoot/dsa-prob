#include <iostream>
using namespace std;

class node
{   public:
    int val;
    node *next;

    node(int x)
    {

        val = x;
        next = NULL;
    }
};

class queue
{   public:
    node *front;
    node *back;

    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int val)
    {
        node *n = new node(val);
        //checking not full
        if(n==NULL){
            cout<<"queue is full"<<endl;
        }

        else{
            if(front==NULL && back==NULL){
                front = n;
                back = n;
            }
            else{
                back->next = n;
                back = n;
            }
        }
        

    }

    bool isempty(){
        if(front==NULL && back==NULL){
            cout<<"queue is empty.."<<endl;
            return true;
        }
        else{
            return false;
        }
    }

    void pop(){
        if(isempty()){
            return;
        }
        else{
            node *todelete;
            todelete = front;
            front = front->next;
            delete todelete;
        }
    }

    int peek(){
        if(isempty()){
            return -1;
        }
        return front->val;
    }


};


int main()
{   queue q;
q.push(1);
q.push(2);
q.push(3);
cout<<q.peek()<<endl;
q.pop();
cout<<q.peek()<<endl;

    return 0;
}