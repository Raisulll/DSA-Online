#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> v[N];
int visited[N];
void dfs(int s)
{
    stack<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int k= q.top();
        q.pop();
        cout<<k<<" ";
        for(int i=0; i<v[k].size(); ++i)
        {
            int t=v[k][i];
            if(visited[t]==0)
            {
                // cout<<t<<endl;
                q.push(t);
                visited[t]=1;
            }
        }
    }
    cout<<"\n";
}
int main()
{
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
    dfs(start);
}
/*
13 12
0 1
0 2
1 3
1 4
1 5
3 9
4 50
5 8
2 6
2 7
6 10
7 30
*/