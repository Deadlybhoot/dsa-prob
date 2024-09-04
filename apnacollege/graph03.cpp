#include <bits/stdc++.h>
using namespace std;
//Aim:-
// For directed graph
//1)For detecting cycle in directed graph...
//2)Connected components ch GFG varun karun ghe sop he..
class Graph
{
    int Vertices;
    vector<int> *adj;
    bool *visited;
    bool *recurStack;

public:
    Graph(int V)
    {
        Vertices = V;
        adj = new vector<int>[Vertices + 1]; //==>main
        visited = new bool[Vertices];
        recurStack = new bool[Vertices];
        for (int i = 0; i < Vertices; i++)
        {
            visited[i] = false;
            recurStack[i] = false;
        }
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void PrintGraph()
    {
        for (int i = 1; i < Vertices + 1; i++)
        {
            cout << i << "->";
            for (auto x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    bool DfsForCycle(int currVertex)
    {
        visited[currVertex] = true;
        recurStack[currVertex] = true;

        for (auto child : adj[currVertex])
        {
            if (!visited[child] && DfsForCycle(child))
            {
                return true;
            }
            else if (recurStack[child])
            {
                return true;
            }
        }
        //he call hoil jevha for loop nahi honar 
        recurStack[currVertex] = false; // remove vertex from recursion stack
        return false;
    }

    bool isCycle()
    {
        for (int i = 0; i < Vertices; i++)
        {
            if (!visited[i] && DfsForCycle(i))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int V = 3;

    Graph g(V);
    g.addEdge(1, 2); //<--
    g.addEdge(2, 3);
    g.addEdge(1,3);
    // g.PrintGraph();
    cout<<g.isCycle();

    return 0;
}