// LCA in graph
//finding common parent of 2 node
#include<bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int>&visited,vector<int>vec[],vector<int>&parent)
{
    visited[v]=1;
    for(auto child:vec[v])
    {
        if(visited[child]) continue;
        parent[child]=v;
        dfs(child,visited,vec,parent);
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
    vector<int>parent(v+1,0);
    dfs(1,visited,vec,parent);
    // till above i got parent of all node
    vector<int>path1;
    int x=6,y=8;
      int par_x = x;
    while (par_x != 0) {  // Stop at root (or parent 0 if using 1-based indexing)
        path1.push_back(par_x);
        par_x = parent[par_x];
    }
    vector<int>path2;
    int par_y = y;
    while (par_y != 0) {
        path2.push_back(par_y);
        par_y = parent[par_y];
    }
    reverse(path1.begin(),path1.end());
    reverse(path2.begin(),path2.end());
    int ans=-1;
    for(int i=0;i<path1.size() && path2.size();i++)
    {
        if(path1[i]==path2[i]) ans=path1[i];
        else
        break;
    }
    cout<<ans;
}