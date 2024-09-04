#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>&st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(num);

}

void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,num);
    
}





int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.top()<<endl;
    reverseStack(st);
    cout<<st.top()<<endl;

    return 0;
}