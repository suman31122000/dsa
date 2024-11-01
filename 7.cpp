//topological sort
//it is an algorithm which is used for linear arranging of node in such way that if v->u then v always come before u
//this algorithm can be implemented by both bfs as well as dfs
//topological sort by dfs 
#include<bits/stdc++.h>
using namespace std;
 void dfs(int v,vector<int>vec[],vector<int>&visited,stack<int>&st){
    visited[v]=1;
    for(auto child:vec[v]){
        if(visited[child]==1) continue;
        dfs(child,vec,visited,st);
    }
    st.push(v);
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
        vec[x].push_back(y);    //it will only applied on dag
    }
    vector<int>visited(v+1,0);
    stack<int>st;

    for(int i=1;i<=v;i++){
        if(visited[i]) continue;
        dfs(i,vec,visited,st);
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for(auto it:ans)
    cout<<it<<" ";
}