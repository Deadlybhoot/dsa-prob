#include<bits/stdc++.h>
using namespace std;

//successfully solved
int main(){
string s = "defRTSersUXI";

cout<<s<<endl;

// map<int, vector<char>> :: iterator it;

// for(int i =0; i<s.size(); i++){
//     if(s[i].islower()){
//         mp[0].push_back(s[i]);
//     }
//     else{
//         mp[1].push_back(s[i]);
//     }
// }

// cout<<mp.second;
//a=upper
string a, b;
for(int i=0; i<s.size(); i++){
    if(isupper(s[i])){
       a += s[i];
    }
    else{
      b += s[i];
    }
}

sort(a.begin(), a.end());
sort(b.begin(), b.end());

for(int i=0; i<s.size(); i++){
    if(islower(s[i])){
        s[i] = b[0];
        b.erase(0,1);
    }
    else{
        s[i] = a[0];
        a.erase(0,1);
    }
}
cout<<s<<endl;
cout<<a<<endl<<b;

// int ct = 0;


//     for(auto x: mp){
//         if(s[ct].islower()){
//             s[ct] = mp.second;
//         }
//     }

// cout<<temp;





    return 0;
}