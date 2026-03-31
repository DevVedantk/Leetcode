class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& edges, vector<int>& time) {
        vector<int>lvl(n+1,0);
     vector<vector<int>>adj(n+1);
     vector<int>deg(n+1,0);
     for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        deg[edges[i][1]]++;
     }
     
     vector<int>dp(n+1);
     queue<pair<int,int>>q;
     for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push({i,0});
        dp[i]=time[i-1];
     }

     while(q.size()>0){
        auto [node,dist]=q.front();
        q.pop();

        for(int child:adj[node]){
            dp[child]=max(dp[child],time[child-1]+dp[node]);
            deg[child]--;
            if(deg[child]==0){
                q.push({child,dist+1});
            }
        }
     }
     
    //  for()
     int ans=0;
     for(int i=0;i<=n;i++) ans=max(ans,dp[i]);
     return ans;
    }
};