#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int graph[N][N];
int visited[N];
int parents[N];
int level[N];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int i = 0; i < N; ++i)
        {
            if (graph[x][i] == 1 and visited[i] == 0)
            {
                level[i] = level[x] + 1;
                q.push(i);
                parents[i] = x;
                visited[i] = 1;
            }
        }
    }
}
void find_path(int start, int des)
{
    vector<int> path;
    while (true)
    {
        path.push_back(des);
        des = parents[des];
        if (des == start)
            break;
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int start, des;
    // cin >> start >> des;
    bfs(start);
    // find_path(start,des);
    // cout << "Parents - Levels\n";
    // for (int i = 0; i < N; ++i)
    // {
    //     if (level[i] != 0 or i == start)
    //     {
    //         cout << i << ": " << level[i] << endl;
    //     }
    // }
}
/*
15 16
0 1
0 2
1 8
1 10
1 12
8 7
10 11
12 13
13 15
11 13
30 15
15 24
2 20
20 21
21 24
20 25
0

*/