#include <iostream>
#include <stack>
using namespace std;

// jevhahi fakt check karnraht tevha boolvapraycha
bool isValid(string s)
{
    stack<char> st;
    bool ans = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }

        // before poping check not empty make habit
        else if (!st.empty() && s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }

            else
            {
                ans = false;
                break;
            }
        }


         else if (!st.empty() && s[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }

            else
            {
                ans = false;
                break;
            }
        }


         else if (!st.empty() && s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }

            else
            {
                ans = false;
                break;
            }
        }



      

      
    }

    if (!st.empty())
    {
        ans = false;
        return ans;
    }

    else
    {
        return ans;
    }
}

int main()
{
    string s = "{([])}";
    if (isValid(s))
    {
        cout << "Valid string" << endl;
    }
    else
    {
        cout << " Invalid string" << endl;
    }

    return 0;
}