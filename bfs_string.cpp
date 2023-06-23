#include <bits/stdc++.h>
using namespace std;
const int N=100;

//? vector<int>zaima[N]; 
//!  1-->
//! 2-->
map<string,vector<string>>zaima;
map<string,bool> visited;
map<string,string>parent;
void bfs(string start)
{
    queue<string> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        string a=q.front();
        q.pop();
        for(int i=0; i<zaima[a].size(); ++i)
        {
            string b=zaima[a][i];
            if(visited[b]==false)
            {
                q.push(b);
                parent[b]=a;
                visited[b]=true;
            }
        }
    }
}
void print_path(string st,string de)
{
    vector<string> path;
    while(true)
    {
        if(st==de)
        {
            path.push_back(de);
            break;
        }
        else
        {
            path.push_back(de);
            de=parent[de];
        }
    }
    for(int i=path.size()-1; i>=0; --i)
    {
        cout<<path[i]<<" ";
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; ++i)
    {
        string a,b;
        cin>>a>>b;
        zaima[a].push_back(b);
        zaima[b].push_back(a);
        visited[a]=false;
        visited[b]=false;
    }
    string a,b;
    cin>>a>>b;
    bfs(a);
    print_path(a,b);
}
/*
5 6
Dhaka Cumilla
Dhaka Narayongonj
Dhaka Khulna
Cumill Narayongonj
Narayongonj Khulna
Cumilla Chittagong
Dhaka Chittagong
*/