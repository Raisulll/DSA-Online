#include <bits/stdc++.h>
using namespace std;
const int N=1000;
vector<int> adj[N];
int visited[N];
int s_time[N];
int f_time[N];
int parent[N];
int t;
void  dfs(int s)
{
    visited[s]=1;
    t++;
    s_time[s]=t;
    for(int i=0; i<adj[s].size(); ++i)
    {
        int v=adj[s][i];
        if(visited[v]==1)
        {
            parent[v]=s;
            dfs(v);
        }
    }
    t++;
    f_time[s]=t;
    visited[s]=-1;
}
int main()
{
    int n,e;
    memset(visited,0,sizeof(visited));
    memset(s_time,0,sizeof(s_time));
    memset(f_time,0,sizeof(f_time)); 
    cin>>n>>e;
    for(int i=0; i<e; ++i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s;
    cin>>s;
    dfs(s);
} 