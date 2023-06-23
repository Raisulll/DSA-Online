#include <bits/stdc++.h>
using namespace std;
int c = 0;
class Prims
{
    map<string, vector<pair<string, int>>> mp;
    map<string, int> vis;

public:
    void addedge(string u, string v, int w)
    { 
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    vector<string> prims(string s)
    {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        q.push({0, s});
        vector<string> ans;
        while (!q.empty())
        {
            pair<int, string> p = q.top();
            q.pop();
            if (vis[p.second])
                continue;
            vis[p.second] = 1;
            ans.push_back(p.second);
            for (auto it : mp[p.second])
            {
                if (!vis[it.first])
                {
                    q.push({it.second, it.first});
                }
                else
                {
                    c++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Prims p;
    int e;
    cin >> e;
    string x, y, z;
    int w, mn = 1e8;
    while (e--)
    {
        cin >> x >> y >> w;
        p.addedge(x, y, w);
        if (w < mn)
        {
            mn = w;
            z = x;
        }
    }
    vector<string> ans = p.prims(z);
    for (int i = 0; i < ans.size() - 1; ++i)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
}