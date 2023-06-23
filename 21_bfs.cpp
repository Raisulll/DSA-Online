#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>> graph;
map<string,int>mp;
map<string,bool>visited;
map<string,string>parent;
map<string,int>level;


int main()
{
    int e;
    cin>>e;
    string a,b;
    for(int i=0; i<e; ++i)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        parent[b]=a;
        level[a]=level[b]=0;
        visited[a]=visited[b]=false;
    }
    string root="C:";
    // bfs(root);
}