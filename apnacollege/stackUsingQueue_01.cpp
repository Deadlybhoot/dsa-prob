#include<iostream>
#include<queue>
using namespace std;
//This approach is by modifying the push operation;
class stack{
    queue<int>q1;
    queue<int>q2;

    public:
    void push(int num){
        //we are pushing to q2 because after swap it will coming to q1;
        q2.push(num);
       

        //puting elelment from q1 to q2;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        //swapping two queues
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;



    }

    int pop(){
        if(q1.empty()){
            cout<<"Stack is empty.."<<endl;
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }
};

int main(){

stack s1;
s1.push(1);
s1.push(2);
s1.push(3);
cout<<s1.pop()<<endl;
cout<<s1.pop()<<endl;
    return 0;
}


