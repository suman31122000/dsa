#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
vector<vector<int>>floyd(int v,vector<pair<int,int>>vec[])
{
    vector<vector<int>>dist(v+1,vector<int>(v+1,INF));
    

    for(int i=0;i<=v;i++)
    {
        dist[i][i]=0;
        for(auto edges:vec[i])
        {
            int child=edges.first;
            int wt=edges.second;
            dist[i][child]=min(wt,dist[i][child]);
        }
    }

    for(int k=1;k<=v;k++)
    {
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++){
                if(dist[i][k]==INF || dist[k][j]==INF) continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
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
   vector<vector<int>>ans= floyd(v,vec);
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans.size();j++)
    {
        cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
    }
  }
}