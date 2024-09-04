#include <iostream>
#include <stack>
using namespace  std;
void reverseString(string s)
{   
    stack<string> st;//You forget that syntax
    // string word = ""; //--You declared here butthis is wrong

    for (int i = 0; i < s.length(); i++)
    {
        string word = ""; //--Declare word variable here

        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }

        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    string s = "AKSHAY SANJAY SATAV";
    reverseString(s);
    return 0;
}