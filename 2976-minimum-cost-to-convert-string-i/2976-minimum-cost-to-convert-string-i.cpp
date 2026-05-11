class Solution {
public:
    long long minimumCost(string src, string t, vector<char>& org, vector<char>& ch, vector<int>& cost) {
         vector<vector<long long>>dp(26,vector<long long>(26,LLONG_MAX));
         vector<vector<pair<long long,long long>>>adj(26);

         for(int i=0;i<org.size();i++){
            char u=org[i],v=ch[i];
            long long wt=cost[i];
            adj[u-'a'].push_back({v-'a',wt});
         }
         for(int i=0;i<26;i++){
            dp[i][i]=0;
         }

         for(int i=0;i<26;i++){
            int u=i;
            for(auto [v,wt]:adj[i]){
                dp[u][v]=min(dp[u][v],wt);
            }
         }

         for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dp[i][k]!=LLONG_MAX && dp[k][j]!=LLONG_MAX){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                    }
                }
            }
         }

         long long cst=0;
         for(int i=0;i<src.size();i++){
            int u=src[i]-'a',v=t[i]-'a';
            if(dp[u][v]==LLONG_MAX) return -1;
            cst+=dp[u][v];
         }

         return cst;
    }
};