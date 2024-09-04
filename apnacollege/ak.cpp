#include<bits/stdc++.h>
using namespace std;

  void findSum(string X, string Y) {
        // Your code goes here
        int n = X.length();
        int m= Y.length();
      
        if(n!=m){
          if(n>m){
            swap(X,Y);
          }
        }
       string x1 = X.substr(0,n/2);
       string x2 = X.substr(n/2, n/2);
          cout<<x2<<endl;
       string y1 = Y.substr(0,m-n/2);
   
       string y2 = Y.substr(m-n/2, n/2);
            cout<<y2<<endl;
       int z2 = stoi(x2) + stoi(y2);

       cout<<z2;
      //  to_string(z2);
      //    string temp;
      //  int k = max(x2.length(), y2.length());
      //  if(z2.length()>max(x2.length(), y2.length())){
      //      int diff = z2.length()- k;
      //      temp = substr(0,diff);
      //      z2 = substr(diff, k);
      //  }
      //  cout<<temp;
      //  int z1 =  stoi(x1) + stoi(y1) + stoi(temp);



       
    }

int main(){
    findSum("1234", "1234");



    return 0;
}