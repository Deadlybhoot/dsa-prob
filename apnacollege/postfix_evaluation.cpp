#include <iostream>
#include <stack>
#include <math.h>

using namespace std;
int postfixEvaluation(string s)
{
    stack<int> st;
    //
    for (int i = 0; i < s.length(); i++)//---->1
    { //---This is the main here start traversing from Left to right
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

    cout << postfixEvaluation("42*3+")<<endl;

    return 0;
}