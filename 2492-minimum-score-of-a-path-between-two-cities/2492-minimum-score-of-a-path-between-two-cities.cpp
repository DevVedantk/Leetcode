class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
         vector<vector<pair<int,int>>>adj(n+1);

         for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1],wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
         }


         queue<pair<int,int>>q;

         q.push({1,INT_MAX});
         int ans=INT_MAX;
       vector<bool>vis(n+1,false);
         while(q.size()>0){
            auto [node,dis]=q.front();
            q.pop();

            ans=min(ans,dis);
            if(vis[node]) continue;
            vis[node]=true;

            for(auto [child,wt]:adj[node]){
                if(!vis[child]){
                 q.push({child,wt});
                }
            }
         }

         return ans;
    }
};