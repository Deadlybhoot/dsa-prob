#include<iostream>
using namespace std;
#define n 100

class stack{
    int*arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
        
    }
    //This are operations we can perform on stack;
    void push(int val){
        if(top == n -1){
            cout<<"Stack overflow.."<<endl;
            return;
        }
        top++;
        arr[top] = val;

    }

    void pop(){
        if(top == -1){
            cout<<"stack is Empty.."<<endl;
            return;
        }
        top--;
    }

    bool empty(){
        return top==-1;
    }

    int Top(){
          if(top == -1){
            cout<<"stack is Empty.."<<endl;
            return -1;
        }
        return arr[top];
    }


};

int main(){

stack st;
st.push(1);
// st.push(2);
// st.push(3);
st.pop();
cout<<st.Top();
cout<<st.empty();





    return 0;
}