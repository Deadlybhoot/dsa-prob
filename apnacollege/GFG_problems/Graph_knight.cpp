#include <bits/stdc++.h>
using namespace std;

// Aim:- For counting number of steps required for knight to reach at destination
// first see the steps of Graph02.cpp BFS alll steps are same like bfs
//Dry run it 

//             |
//             |  2
//             |   
//             |  1
// --------------------------------------------|
//  -2     -1     1      2
//         -1  | 
//             |
//             |
//      -2     |
//             |






struct cell
{
    int steps;
    int x;
    int y;
    cell(int X, int Y, int Steps)
    {
        x = X;
        y = Y;
        steps = Steps;
    }
};

bool isInside(int x, int y, int n)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n)
    {
        return true;
    }
    return false;
}

// take reference of BFS code.
int minStepsTOReachTarget(int knight[], int target[], int n)
{
    queue<cell> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false)); // imagine how one vector initiase

    int dis = 0;
    cell t(knight[0], knight[1], dis);
    int x, y; // why made you will get later

    //make it by varcha graph
    //we are maintaining this two ararys for moving on their childs
    //Let x=colomns, y=rows
    int dx[] = {-2, -2, 2, 2, -1, 1, 1, -1};
    int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};


    q.push(t);
    visited[t.x][t.y] = true;

    while (!q.empty())
    {
        t = q.front();
        q.pop();

        if (t.x == target[0] && t.y == target[1])
        {
            return t.steps;
        }

        for (int i = 0; i < 8; i++)
        {
            // t.x = t.x + dx[i];
            // t.y = t.y + dy[i];
            x = t.x + dx[i];
            y = t.y + dy[i];

            if (isInside(x, y, 6) && (!visited[x][y]))
            {
                visited[x][y] = true;
                q.push(cell(x, y, t.steps + 1)); // mark
            }
        }
    }
}

int main()
{
    int knight[] = {1, 1};
    int target[] = {6, 6};
    int r = minStepsTOReachTarget(knight, target, 6);
    cout << "The steps required to reach are:- " << r;

    return 0;
}