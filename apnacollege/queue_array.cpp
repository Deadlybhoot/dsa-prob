#include<iostream>
using namespace std;
#define n 20
class queue{

    int *arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){
    if(arr[back]==n-1){
        cout<<"queue is overflow.."<<endl;
        return;
    }

   else{
       back++;
       arr[back] = x;
       if(front==-1){
           front++;
       }
   }
    }

   void pop(){
       if(back==-1 && front > back){
           cout<<"queue is empty.."<<endl;
           return;
       }
       else{
           front++;
       }
   }

   int peek(){
        if(back==-1 && front > back){
           cout<<"queue is empty.."<<endl;
           return -1;
       }

       else{
           return arr[front];
       }
   }

};
    





int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;



    return 0;
}