class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=edges.size()+1;
        vector<vector<pair<int,int>>>adj(n);
         for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
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
            if(dist[child]>wt+dis){
                dist[child]=wt+dis;
                pq.push({dist[child],child});
            }
        }
     }
      
      int ans=0;
      for(int i=0;i<patience.size();i++){
        if((dist[i]*2)<=patience[i]) ans=max(ans,dist[i]*2);
        else{
          int last_msgtime=(((2*dist[i])-1)/patience[i])*patience[i];
          ans=max(ans,last_msgtime+dist[i]*2);
        }
      }

      return ans+1;

    }
};