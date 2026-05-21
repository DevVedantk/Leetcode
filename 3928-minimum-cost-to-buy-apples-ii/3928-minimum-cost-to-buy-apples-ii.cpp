class Solution {
public:

     long long dijkstra(vector<vector<int>>& edges,int n,int src,vector<int>&price,
       vector<vector<pair<long long,long long>>>&adj1,vector<vector<pair<long long,long long>>>&adj2){
          
            vector<long long>dist1(n,LLONG_MAX);
            vector<long long>dist2(n,LLONG_MAX);

            dist1[src]=0;
            priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;

            pq.push({0,src});

            while(pq.size()>0){
                auto [dis,node]=pq.top();
                pq.pop();

                if(dis>dist1[node]) continue;

                for(auto [child,wt]:adj1[node]){
                    if( dist1[child]>dis+wt){
                        dist1[child]=dis+wt;
                        pq.push({dist1[child],child});
                    }
                }
            }

            pq.push({0,src});
            dist2[src]=0;

            while(pq.size()>0){
                auto [dis,node]=pq.top();
                pq.pop();

                if(dis>dist2[node]) continue;

                for(auto [child,wt]:adj2[node]){
                    if(dist2[child]>dis+wt){
                        dist2[child]=dis+wt;
                        pq.push({dist2[child],child});
                    }
                }
            } 

            // cout  <<"from  end to start again " << dist2[src] << endl;
              long long ans=price[src];

              for(int j=0;j<n;j++){
                if(dist1[j]==LLONG_MAX || dist2[j]==LLONG_MAX) continue;

                ans=min(ans,dist1[j]+dist2[j]+price[j]);
              }

              return ans;
     }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& edges) {
               
          vector<int>ans(n);

            vector<vector<pair<long long,long long>>>adj1(n);
            vector<vector<pair<long long,long long>>>adj2(n);

            for(int i=0;i<edges.size();i++){
                long long u=edges[i][0],v=edges[i][1],wt=(long long)edges[i][2];
                long long tax=edges[i][3];
                adj1[u].push_back({v,wt});
                adj1[v].push_back({u,wt});
                adj2[u].push_back({v,(long long)wt*tax});
                adj2[v].push_back({u,(long long)wt*tax});
            }

          for(int i=0;i<n;i++){
             int cost=dijkstra(edges,n,i,prices,adj1,adj2);
             ans[i]=min(prices[i],cost);
          }

          return ans;

    }
};