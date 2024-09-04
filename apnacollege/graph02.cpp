#include<bits/stdc++.h>
using namespace std;

//programiz


class  Graph{
    public:
    int numVertices;
    vector<int>*adj;
    queue<int>q;
    bool *visited;
    
    Graph(int vertices, vector<int>v[]){
        numVertices = vertices;
        adj = v;
        //or you can also allocate it dynamically

        visited = new bool[numVertices];
    //initialising with 0's
    for(int i=0; i<numVertices; i++){
        visited[i] = false;
    }
    }

//src = source, dest = destination;
void addEdges(int src, int dest){
    //undirected
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}


void PrintGraph(){
    for(int i = 1; i<numVertices+1; i++){
        cout<<i<<"->";
        for(auto x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

// to write think that gaph is tree
void Bfs(int startVertex){
    // visited = new bool[numVertices];
    // //initialising with 0's
    // for(int i=0; i<numVertices; i++){
    //     visited[i] = false;
    // }
    q.push(startVertex);
    visited[startVertex] = true;

    while(!q.empty()){
        int currVertex = q.front();
        cout<<currVertex<<" ";
        q.pop();
        for(auto child: adj[currVertex]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }
        }

    }
}


void Dfs(int startVertex){
    //here remeber visited array needs to initialise with false before use here we put our visited directly into constructor hence no problem will happened
    visited[startVertex] = true;
    cout<<startVertex<<" ";
    for(auto child: adj[startVertex]){
        if(!visited[child]){
            visited[child] = true;
            Dfs(child);
        }
    }
}


bool DfsOnChilds(int currVertex, int parent){
    visited[currVertex] = true;
    for(auto child: adj[currVertex]){
        if(!visited[child]){
            
            if(DfsOnChilds(child, currVertex)){
                return true;
            }
        }
        else if(child != parent){
            return true;
        }
    }
    return false;
}

bool isCyclic(){
    //If graph is connected then we can dected cycle is present or not by just one  vertex but if Not then we have check all vertex hence we taking loop here
    for(int i =1; i<numVertices+1; i++){
        if(!visited[i]){
            if(DfsOnChilds(i, -1)){
                return true;
            }

        }

    }
    return false;
}

void printVector(){
    for(int i=1; i<numVertices+1; i++){
        for(auto x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

};



int main(){
int V = 3;
//taken V+1 due to we must have to take print function starts from 1; & ends to <n+1 
vector<int>temp[V+1];
Graph g(V, temp);
//apna college graph
//remember one very important thing while giving input give input You caN take preferance of it..Here we taken input like directed in while putting it in vector wemake it as undirected
//In simple words dont repeat edges here while taking input
// g.addEdges(1,2);
// g.addEdges(1,3);
// g.addEdges(2,4);
// g.addEdges(2,5);
// g.addEdges(2,6);
// g.addEdges(2,7);
// g.addEdges(7,3);
g.addEdges(1,2);//<--
// g.addEdges(1,3);
g.addEdges(2,3);


g.PrintGraph();
// g.Bfs(1);
cout<<endl;
// g.Dfs(1);
cout<<g.isCyclic();

cout<<endl;
g.printVector();
    return 0;
}