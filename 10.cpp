#include<bits/stdc++.h>
using namespace std;
const int INF=INT_MAX;
vector<int> dijkstra(int v,vector<pair<int,int>>vec[])
{
    vector<int>dist(v+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty())
    {
        auto node=pq.top();
        int cnode=node.second;
        int  wt=node.first;
        pq.pop();

         if (wt > dist[cnode]) {
            continue;
        }
        for(auto nnode:vec[cnode])
        {
            int  child=nnode.second;
            int  nwt=nnode.first;
            if(dist[cnode]+nwt<dist[child])
            {
                dist[child]=dist[cnode]+nwt;
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
      cin>>x>>y;
      vec[x].push_back({wt,y});
      vec[y].push_back({wt,x});
    }
    vector<int>ans=dijkstra(v,vec);

    for(auto it:ans)
    cout<<it<<" ";
    cout<<suman<<endl;
}