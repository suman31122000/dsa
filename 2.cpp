//bfs algorithm
//bfs algorithm is an graph traversal algorithm which is used to traverse level wise in the graph

#include<bits/stdc++.h>
using namespace std;
void bfs(int v,vector<int>vec[],vector<int>&visited)
{
    queue<int>q;
    q.push(v);
    visited[v]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<endl;
        for(auto child:vec[node])
        {
            if(visited[child]) continue;
            q.push(child);
             visited[child]=1;
        }
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

    for(int i=1;i<=v;i++)
    {
        if(visited[i]) continue;
        bfs(i,vec,visited);
    }
}