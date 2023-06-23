//! vertex should be equal to graph node. and edge shuuld be n-1 where n is the number of node
//! min spanning tree - weight of spanning tree should be minimum.
#include <bits/stdc++.h>
using namespace std;
#define edge pair<int, int>

class Grpah
{
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T;
    int parent[10];

public:
    Grpah(int v)
    {
        for (int i = 0; i < v; ++i)
        {
            parent[i] = i;
        }
    }
    void Add_edge(int u, int v, int w)
    {
        G.push_back({w, {u, v}});
        // G.push_back(make_pair(w,make_pair(u,v)));
    }
    int find_set(int i)
    {
        if (i == parent[i])
        { 
            return i;
        }
        else
        {
            return find_set(parent[i]);
        }
    }
    void Union_set(int u, int v)
    {
        parent[u] = parent[v];
    }
    void Kruskal()
    {
        sort(G.begin(), G.end());
        int uRep, vRep, i;
        for (i = 0; i < G.size(); ++i)
        {
            uRep = find_set(G[i].second.first);
            vRep = find_set(G[i].second.second);
            if (uRep != vRep)
            {
                T.push_back(G[i]);
                Union_set(uRep,vRep);
            }
        }
    }
    void print()
    {
        for(int i=0; i<T.size(); ++i)
        {
            cout<<T[i].second.first<<" "<<T[i].second.second<<" "<<T[i].first<<endl;
        }
    }
};

int main()
{
    Grpah g(5);
    g.Add_edge(0, 1, 2);
    g.Add_edge(0, 3, 4);
    g.Add_edge(0, 2, 1);
    g.Add_edge(1, 3, 3);
    g.Add_edge(1, 2, 2);
    g.Add_edge(1, 4, 1);
    g.Add_edge(2, 3, 3);
    g.Add_edge(2, 4, 4);
    g.Kruskal();
    g.print();
}