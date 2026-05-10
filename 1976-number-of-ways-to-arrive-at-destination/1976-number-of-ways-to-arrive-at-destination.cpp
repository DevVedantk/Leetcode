class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<vector<pair<int,int>>>adj(n);
         for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1],wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
         }
         
         vector<long long>dist(n,LLONG_MAX);
          vector<long long>count(n,0);   
         priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
         

         dist[0]=0;
         count[0]=1;
           pq.push({0,0});
           int MOD=1e9+7;

       while(pq.size()>0){
        auto [dis,node]=pq.top();
        pq.pop();
        
        if(dis>dist[node]) continue;
        for(auto [child,wt]:adj[node]){
            if(dist[child]>dis+wt){
                dist[child]=dis+wt;
                pq.push({dist[child],child});
                count[child]=count[node];
            } else if(dist[child]==dis+wt){
                count[child]=(count[child]+count[node])%MOD;
            }
        }
       }
       
    //    if(dist[n-1]==INT_MAX) return -1;
       return count[n-1];
    }
};