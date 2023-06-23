#include <bits/stdc++.h>
using namespace std;
class Prims
{
    map<int, vector<pair<int, int>>> adj; // u->v,w;
    map<int, int> visited;

public:
    void addEdges(int u, int v, int w)//! u,w/v,w
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> prims(int src)
    {
        // priority_queue<int>a;
        // priority_queue<int,vector<int>,greater<int>>b;
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});//! w,u/w,v
        vector<int> ans;
        while (!pq.empty())
        {
            pair<int, int> Top = pq.top();
            pq.pop();
            if (visited[Top.second])
                continue;
            visited[Top.second] = 1;
            ans.push_back(Top.second);
            for (auto i : adj[Top.second])
            {
                if (!visited[i.second])
                    pq.push({i.second,i.first});
            }
        }
        return ans;
    }
};
int main()
{
    Prims p;
    int edges;
    cin >> edges;
    int mn=1e6;
    int x;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        p.addEdges(u, v, w);
        if(w<mn)
        {
            mn=w;
            x=u;
        }
    }
    vector<int> ans = p.prims(x);
    for(int i=0; i<ans.size()-1; ++i)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    cout << endl;
}