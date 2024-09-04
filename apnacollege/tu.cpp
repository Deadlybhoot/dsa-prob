#include <bits/stdc++.h>
using namespace std;
//he cheating ch
 string findSum(string X, string Y) {
        int n=X.size();
        int m=Y.size();
        
        reverse(X.begin(),X.end());
        reverse(Y.begin(),Y.end());
        
        int c=0;
        string ans="";
        for(int i=0;i<max(n,m);i++)
        {
            int cur=c;
            if(i<n)
                cur+=X[i]-'0';
            if(i<m)
                cur+=Y[i]-'0';
                
            c=cur/10;
            cur%=10;
            ans.push_back(cur+'0');
        }
        // cout<<"y\n";
        if(c>0)
            ans.push_back(c+'0');
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() and ans[i]=='0')i++;
        
        
        reverse(X.begin(),X.end());
        reverse(Y.begin(),Y.end());
        ans= ans.substr(i,ans.size()-i);
        
        if(ans.size()==0)return "0";
        return ans;
    }



string findSum(string X, string Y)
{
    // Your code goes here
    int carry = 0;
    int n1 = X.length();
    int n2 = Y.length();
    // that just means we need maximum length string at Y
    if (n1 > n2)
    {
        swap(X, Y);
    }
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());

    string str = "";
    for (int i = 0; i < n1; i++)
    {
        int sum = ((X[i] - '0') + (Y[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++)
    {
        int sum = ((Y[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    if (carry)
    {
        str.push_back(carry + '0');
    }
    reverse(str.begin(), str.end());

//   int  n = str.size();
   
//         int i;
//     for( i=0; i<n; i++){
//         if((str[i]-'0') > 0 && (str[i]-'0')<= 9){
//             break;
//         }
//     }
//     if(i==n){
//         return "0";
//     }
//    else{ string s1 = str.substr(i, n-i+1);
//     return s1;
//    }


   int i = 0, n = str.size();
        while (i < n and str[i] == '0') i++;

        if (i == n) return "0";

        return str.substr(i, (int)str.size() - i + 1);

}
int main()
{
    cout << findSum("000000", "000000000");

    return 0;
}