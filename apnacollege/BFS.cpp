#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;


int main(){


vector<int> g[N];
int n, E;
cout<<"Enter number of Nodes:-";
cin>>n;
cout<<"Enter number of Edges:-";
cin>>E;
    int U,V;
for(int i=0; i<n; i++){
    cout<<"Enter two edges 'u' 'v'";
    cin>>U >>V;
    g[U].push_back(V);
    g[V].push_back(U);
}

for(int i=0; i<n; i++){
    for(auto x: g[i]){
        cout<<x;
    }
}

    return 0;
}