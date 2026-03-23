class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=0;i<times.size();i++){
            int u=times[i][0],v=times[i][1],wt=times[i][2];

            adj[u].push_back({v,wt});
        }

        dist[k]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,k});

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
       
       int ans=INT_MIN;
       for(int i=1;i<=n;i++){
        ans=max(ans,dist[i]);
       }

       return ans==INT_MAX ? -1 : ans;

    }
};