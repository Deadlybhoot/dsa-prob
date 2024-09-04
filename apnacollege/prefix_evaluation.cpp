#include <iostream>
#include <stack>
#include <math.h>

using namespace std;
int postfixEvaluation(string s)
{
    stack<int> st;
    //
    for (int i = s.length()-1; i >= 0; i--)//---->s.lengt()-1 this is main
    { //---This is the main here start traversing from right to left
        // if operand
        if (s[i]>='0' && s[i]<='9')
        {
            st.push(s[i] - '0');
        }
        // if operator
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;

            case '-':
                st.push(op1 + op2);
                break;

            case '*':
                st.push(op1 * op2);

                break;

            case '/':
                st.push(op1 / op2);

                break;

            case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
   
    return st.top();
}

int main()
{
    string s = "-+7*45+20";

    cout << postfixEvaluation("+*423")<<endl;

    return 0;
}