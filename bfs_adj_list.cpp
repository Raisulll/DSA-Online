#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100;
vector<int>v[N];
int visited[N];
int parents[N];
int level[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        cout<<k<<" ";
        for(int i=0; i<v[k].size(); ++i)
        {
            int t=v[k][i];
            if(visited[t]==0)
            {
                q.push(t);
                parents[t]=k;
                level[t]=level[k]+1;
                visited[t]=1;
            }
        }
    }
    cout<<endl;
}
void find_path(int r,int d)
{
    vector<int> ans;
    while(true)
    {
        if(d==r)
        {
            ans.push_back(d);
            break;
        }
        else
        {
            cout<<d<<"\n";
            ans.push_back(d);
            d=parents[d];
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}
void init()
{
    for(int i=0; i<N; ++i)
    {
        parents[i]=-1;
    }
}
int main()
{
    init();
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; ++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int start;
    cin>>start;
    bfs(start);
    int des;
    cin>>des;
    find_path(start,des);
    for(int i=0; i<N; ++i)
    {
        if(parents[i]!=-1 )
        {
            cout<<i<<"  "<<parents[i]<<endl;
        }
    }
}
/*
13 13
0 1
0 2
1 3
1 4
1 5
3 9
4 50
5 8
5 30
2 6
2 7
6 10
7 30
*/