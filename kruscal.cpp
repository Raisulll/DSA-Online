#include <bits/stdc++.h>
using namespace std;

class Kruscal
{
    multimap<int,pair<int,int>>mp;
    map<int,int>parent;
    public:
    void addEdge(int u,int v,int w)
    {
        mp.insert({w,{u,v}});
        parent[u]=u;
        parent[v]=v;
    }
    int findRep(int u)
    {
        if(parent[u]==u) return u;
        else 
        {
            parent[u]=findRep(parent[u]);
        }
    }
    bool Union(int u,int v)
    {
        int x=findRep(u);
        int y=findRep(v);
        if(x!=y)
        {
            parent[x]=y;
            return true;
        }
        return false;
    }
    vector<pair<int,pair<int,int>>> FindMST()
    {
        vector<pair<int,pair<int,int>>> r;
        for(auto it:mp)
        {
            if(Union(it.second.first,it.second.second))
            {
                r.push_back({it.first,{it.second.first,it.second.second}});
            }
        }
        return r;
    }
};

int main()
{
    Kruscal k;
    int e;
    cin>>e;
    for(int i=0; i<e; ++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        k.addEdge(a,b,c);
    }
    int cost=0;
    vector<pair<int,pair<int,int>>>result=k.FindMST();
    for(auto it:result)
    {
        cout<<it.second.first<<" "<<it.second.second<<endl;
        cost+=it.first;
    }
    cout<<cost<<endl;
    return 0;
}