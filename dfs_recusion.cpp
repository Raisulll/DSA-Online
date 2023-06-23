#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int>v[N];
int color[N];

//! 5->> 8 9 7
//? 8->> 5 7
void dfs(int s)
{
    color[s]=1;
    cout<<s<<" ";
    // cout<<"Color of "<<s<<" is Gray now.\n";
    for(int i=0; i<v[s].size(); ++i)
    {
        int t=v[s][i];
        if(color[t]==0)
        {
            dfs(t);
        }
    }
    color[s]=2;
    cout<<"Color of "<<s<<" is Black now.\n";
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; ++i)
    {
        int x,y;
        cin>>x>>y;//! 5 8
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int s;
    cin>>s;
    dfs(s);
}