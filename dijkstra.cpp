#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> adj[N];
vector<int> visited(N);
vector<int> parenst(N,-1);
vector<int> dist(N, INFINITY);
void dijkstra(int start)
{
    set<pair<int, int>> st;
    st.insert({0,start});
    while(!st.empty())
    {
        auto node=*st.begin();
        int v=node.second;
        int d=node.first;
        st.erase(st.begin());
        if(visited[v]==1) continue;
        visited[v]=1;
        for(int i=0; i<adj[v].size(); ++i)
        {
            int child_v=adj[v][i].first;
            int wt=adj[v][i].second;
            if(dist[v]+wt<dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                parenst[child_v]=v;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}
void print_shortest_path(int s, int d)
    {
        vector<int>path;
        while(true)
        {
            if(d==s)
            {
                path.push_back(d);
                break;
            }
            else
            {
                path.push_back(d);
                d=parenst[d];
            }
        }
        for(int i=path.size()-1; i>=0; --i)
        {
            cout<<path[i]<<" ";
        }
    }
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    int start,des;
    cin>>start>>des;
    dijkstra(start);
    print_shortest_path(start,des);
}
/*
6
9
1 2 1
1 3 5
2 3 2
2 5 1
2 4 2
3 5 2
4 5 3
4 6 1
5 6 2
*/