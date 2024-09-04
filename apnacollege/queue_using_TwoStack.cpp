#include<iostream>
using namespace std;
#include<stack>

//Queue using Two stacks
class queue{
    stack<int>s1;
    stack<int>s2;

    public:
    void push(int num){
        s1.push(num);
    }

    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }



};



int main(){
queue q;
q.push(1);
q.push(2);
q.push(3);
cout<<q.pop();
cout<<q.pop();


    return 0;
}