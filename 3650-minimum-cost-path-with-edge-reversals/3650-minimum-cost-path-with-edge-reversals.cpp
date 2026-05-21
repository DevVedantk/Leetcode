class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
          vector<vector<pair<int,int>>>adj(n);


          for(int i=0;i<edges.size();i++){
             int u=edges[i][0],v=edges[i][1],wt=edges[i][2];

             adj[u].push_back({v,wt});
             adj[v].push_back({u,2*wt});
          }

          vector<int>dist(n,INT_MAX);

          dist[0]=0;

          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

          pq.push({0,0});

          while(pq.size()>0){
             auto [dis,node]=pq.top();
             pq.pop();

             if(dis>dist[node]) continue;

             for(auto [child,wt]:adj[node]){
                if(dist[child]>dis+wt){
                    dist[child]=dis+wt;
                    pq.push({dist[child],child});
                }
             }
          }

          return dist[n-1]==INT_MAX ? -1 : dist[n-1];

    }
};