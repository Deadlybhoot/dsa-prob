#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int>s1;

    public:
    void push(int num){
        s1.push(num);
    }

    int q_pop(){//--->q_pop for not to confuse
        if(s1.empty()){
            cout<<"Queue is empty.."<<endl;
            return -1;
        }

        int num = s1.top();
        s1.pop();
        
        if(s1.empty()){
            return num;
        }

        int ans = q_pop();
        s1.push(num);
        return ans;
    }
};



int main(){

queue q1;
q1.push(1);
q1.push(2);
q1.push(3);
cout<<q1.q_pop();
cout<<q1.q_pop();



    return 0;
}