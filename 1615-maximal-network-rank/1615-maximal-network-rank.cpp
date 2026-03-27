class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n);
      vector<vector<bool>>check(n,vector<bool>(n));
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1];
            deg[u]++;deg[v]++;
            check[u][v]=true;
            check[v][u]=true;
        }
        
      
        int ans=-1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(check[i][j] || check[j][i]){
                    ans=max(ans,deg[i]+deg[j]-1);
                } else ans=max(ans,deg[i]+deg[j]);
            }
        }

        return ans;
    }
};