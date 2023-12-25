// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int V=9;
  void solve(int src,vector<pair<int,int>> adj[])
  {
    vector<int> dis(30,-1);
    priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,src});
    dis[src] = 0;
    while(q.size())
    {
      auto cur = q.top();q.pop();
      for(auto p:adj[cur.second])
      {
        int nv = p.first,nc = p.second;
        if(dis[p.first] == -1 || dis[p.first] > cur.first + p.second  )
        {
          dis[p.first] = cur.first + p.second;
          q.push({dis[p.first],p.first});
        }
      }
    }
    for(int i=0;i<9;i++)
    {
      cout<<i<<" "<<dis[i]<<endl;
    }
    return;
  }

int main() {
  
  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
                        
    vector<pair<int,int>> adj[30];
    for(int i=0;i<9;i++)
      for(int j=0;j<9;j++)
      {
        if(graph[i][j])
        {
          adj[i].push_back({j,graph[i][j]});
        }
      }
    solve(0,adj);
  // return;
}