class Solution {
public:

bool check(vector<vector<pair<int,int>>>&adj,long long k,long long mid,int n){
       vector<long long>dist(n,LLONG_MAX);

       priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

       pq.push({0ll,0});
       dist[0]=0ll;

       while(pq.size()>0){
          
          auto [dis,node]=pq.top();
          pq.pop();
          if(dis>dist[node]) continue;

          for(auto [child,wt]:adj[node]){
            if(wt>=mid && dist[child]>dis+wt){
               dist[child]=dis+wt;
               pq.push({dist[child],child});
            }
          }
       }

       return (dist[n-1]<=k);

}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
          
         int n=online.size();
         vector<vector<pair<int,int>>>adj(n);

         for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],cost=edges[i][2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v,cost});
         }


         long long ans=-1;
         
         long long lo=0,hi=1e9;
         while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            if(check(adj,k,mid,n)){
                ans=mid;
                lo=mid+1;
            } else hi=mid-1;
         }

         return ans;
    }
};