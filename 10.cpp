#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
vector<int>dijkstra(int v,vector<pair<int,int>>vec[])
{
    vector<int>dist(v+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty())
    {
        auto cnode=pq.top();
        int wt=cnode.first;
        int node=cnode.second;
        pq.pop();
        if(dist[node]<wt) continue;
        for(auto nnode:vec[node])
        {
            int child=nnode.first;
            int nwt=nnode.second;
            if(dist[node]+nwt<dist[child])
            {
                dist[child]=dist[node]+nwt;
                pq.push({dist[child],child});
            }
        }
    }
    return dist;

}
int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>>vec[v+1];
    for(int i=0;i<e;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        vec[x].push_back({y,wt});
        vec[y].push_back({x,wt});
    }
   vector<int>ans= dijkstra(v,vec);
  for(int i=0;i<ans.size();i++)
  {
    cout<<i <<" "<<ans[i]<<endl;
  }
}