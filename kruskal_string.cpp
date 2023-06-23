#include <bits/stdc++.h>
using namespace std;

class kruskal
{
public:
    multimap<int, pair<string, string>> mp;
    map<string, string> parent;
    void addEdge(string u, string v, int w)
    {
        mp.insert({w, {u, v}});
        parent[u] = u;
        parent[v] = v;
    }
    string findRep(string u)
    {
        if (parent[u] == u)
            return u;
        else
        {
            parent[u] = findRep(parent[u]);
            return parent[u];
        }
    }
    bool Union(string u, string v)
    {
        string x = findRep(u);
        string y = findRep(v);
        if (x != y)
        {
            parent[x] = y;
            return true;
        }
        return false;
    }

    vector<pair<int, pair<string, string>>> FindMST()
    {
        vector<pair<int, pair<string, string>>> v;
        for (auto it : mp)
        {
            if (Union(it.second.first, it.second.second))
            {
                v.push_back(it);
            }
        }
        return v;
    }
};

int main()
{
    kruskal k;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        string u, v;
        int w;
        cin >> u >> v >> w;
        k.addEdge(u, v, w);
    }
    vector<pair<int, pair<string, string>>> o = k.FindMST();
    int cost = 0;
    cout << endl;
    for (auto it : o)
    {
        cout << it.second.first << " " << it.second.second << " " << it.first << endl;
        cost += it.first;
    }
    cout << cost << endl;
}
/*
9
Dhaka chittagong 1
Dhaka comilla 2
chittagong rajshahi 2
comilla rajshahi 3
rajshahi khulna 3
chittagong rangpur 3
khulna jessore 4
chittagong jessore 4
jessore rangpur 5
*/