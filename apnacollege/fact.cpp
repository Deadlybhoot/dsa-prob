#include<iostream>
using namespace std;



int  fact(int n){
if(n==0){
    return 1;
}
   
    int total = 1;
 return  total =  n* fact(n-1);
   
  
}

int main(){

int ans = fact(5);
cout <<ans<<endl;

    return 0;
}
