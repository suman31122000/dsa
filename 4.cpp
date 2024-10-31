//connected component in a grapgh
//connected commponetare those graph in which we can traverse to each node from every node

#include<bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int>&visited,vector<int>vec[])
{
    if(visited[v]) return;
    visited[v]=1;
    for(auto child:vec[v])
    {
        dfs(child,visited,vec);
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>vec[v+1];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    vector<int>visited(v+1,0);
    int count=0;
    for(int i=1;i<=v;i++)
    {
        if(visited[i]) continue;
         count++;
         dfs(i,visited,vec);
    }
    cout<<count<<endl;
}