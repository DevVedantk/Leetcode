class Solution {
public:

bool find(vector<vector<int>>&edges,int threshold,int n,int src, int target, int k){
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<vector<pair<int,int>>>adj(n);
            for(int i=0;i<edges.size();i++){
                int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
                if(wt<=threshold){
                    adj[u].push_back({v,0});
                    adj[v].push_back({u,0});
                } else{
                adj[u].push_back({v,1});
                    adj[v].push_back({u,1});    
                }
            }

            vector<int>dist(n,INT_MAX);
            pq.push({0,src});
            dist[src]=0;

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

            return (dist[target]<=k); 
}
    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int target, int k) {
        
           

           int lo=0,hi=1e9;
            int ans=-1;
           while(lo<=hi){
               int mid=lo+(hi-lo)/2;
              
              bool get_ans=find(edges,mid,n,src,target,k);
              if(get_ans){
                ans=mid;
                hi=mid-1;
              } else lo=mid+1;
          
           }

            return ans;

    }
};