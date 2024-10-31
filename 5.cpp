// precompution of graph
//calculating the total sum of its subtree
#include<bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int>vec[],vector<int>&visited,vector<int>&subtreeSum){
    visited[v]=1;
    subtreeSum[v]+=v;
    for(auto child:vec[v])
    {
        if(visited[child]) continue;     // always check visited node here because if we dont do it here then it will add multiple times 
        dfs(child,vec,visited,subtreeSum);
        subtreeSum[v]+=subtreeSum[child];
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
    vector<int>subtreeSum(v+1,0);
    vector<int>visited(v+1,0);
    dfs(1,vec,visited,subtreeSum);
    for(int i=1;i<=v;i++)
    cout<<i<<" "<<subtreeSum[i]<<endl;

}