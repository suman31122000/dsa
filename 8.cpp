//topological sort using bfs
//it is alson know as kahns algorithm 
//this algorithm is used when we heave question like dependency before doing this you have to done with that

#include<bits/stdc++.h>
using namespace std;
vector<int>bfs(int v,vector<int>vec[])
{
    vector<int>indegree(v+1,0);
    for(int i=1;i<=v;i++)
    for(auto it:vec[i])
    {
        indegree[it]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>toposort;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        toposort.push_back(node);
        for(auto neighbour:vec[node])
        {
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }
    return toposort;
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
    }
   vector<int>ans= bfs(v,vec);
   for(auto it:ans)
   cout<<it<<" ";
}