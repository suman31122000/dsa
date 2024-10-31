//dfs algorithm
#include<bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int>vec[],vector<int>&visited)
{
    if(visited[v]) return;
    visited[v]=1;
    cout<<v<<endl;
    for(auto child:vec[v])
    {
        dfs(child,vec,visited);
    }
}
int main(){
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
    dfs(1,vec,visited);
}