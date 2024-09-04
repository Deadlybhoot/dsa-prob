#include <iostream>
#include <stack>
using namespace std;

int precedance(char c)
{
    // Follow BODMAS
    // In three types we classified that operators
    if (c == '^')
    {
        return 3;
    }

    else if (c == '*' || c == '/')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }

    // This will execute when there is open or close bracket
    else
    {
        //-1 due to lowest
        return -1;
    }
}

string infixToPrefix(string s)
{
    // main we need stack of char data type
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {  
         //This while loop poping all operators of first paranthesis to the outside of it until second paranthesis's open bracket not occured
        //remeber jad-jadi pop karto he tadi stack not empty he check karun ghetl he
            while (!st.empty() && st.top() != '(')
            { //---remember we have find '(' in the stack not on the string
                res += st.top();
                st.pop();
            }

            // after while loop if stack not empty & open bracket occured '(' then we have to remove it '(' From stack
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
        }
        // for operators
        else
        {
            while (!st.empty() && precedance(s[i]) < precedance(st.top()))//-->until pecedance of s[i] < (sign is main) precedance of st.top 
            {
                res += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    // After string over pop all and all char to res
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    cout << infixToPrefix("(a*b/c)*(a/k-l)") << endl;

    return 0;
}
