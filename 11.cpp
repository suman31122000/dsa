#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
vector<int>bellman(int v,vector<pair<int,int>>vec[])
{
    vector<int>dist(v+1,INF);
    dist[1]=0;

    for(int i=1;i<=v-1;i++)
    {
        for(int j=0;j<=v;j++)
        for(auto node:vec[j])
        {
            int child=node.first;
            int wt=node.second;
            if(dist[j]+wt<dist[child])
            {
                dist[child]=dist[j]+wt;
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
   vector<int>ans= bellman(v,vec);
  for(int i=0;i<ans.size();i++)
  {
    cout<<i <<" "<<ans[i]<<endl;
  }
}