#include <bits/stdc++.h>
using namespace std;
// Program to find the length of the largest island
// region in boolean 2D-matrix using BFS
void Bfs(vector<vector<int>> &matrix, int n, int m, int i, int j, int &count)
{
    queue<pair<int,int>> q;//queue hi pair chi kahun banavli he pudhe samjel
    q.push({i,j});
    matrix[i][j] = -1;
    // 1,0,-1
    // we have to find in 8 directions;
    // if 4 then dont take last 4 pairs
    int row[] = {0, 1, 0, -1, 1, -1, 1, -1};
    int col[] = {1, 0, -1, 0, -1, 1, 1, -1};

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (int k = 0; k < 8; k++)
        {   //here je i & j plus karto he te current element jo queue madhun baher padla tyache pahije
            //hence we made queue of pair
            // int x = i + row[k];===>aas direct nahi chalat
            // int y = j + col[k];

            int x = temp.first + row[k];//===>aas direct nahi chalat
             int y = temp.second + col[k];

            if (x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] == 1)
            {
                q.push(make_pair(x,y));
                count += 1;
                matrix[x][y] = -1;
            }
        }
    }
}

int maximumIsland(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxarea = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                count = 1;
                Bfs(matrix, n, m, i, j, count);
                maxarea = max(maxarea, count);
            }
        }
    }
    return maxarea;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 1, 1, 0},
                                  {1, 0, 1, 1, 0},
                                  {0, 1, 0, 0, 0},
                                  {0, 0, 0, 0, 1}};

    cout << maximumIsland(matrix);

    return 0;
}