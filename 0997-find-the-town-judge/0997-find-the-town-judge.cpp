class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<trust.size();i++){
            adj[trust[i][1]].push_back(trust[i][0]);
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==n-1) ans=i;
        }

        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==ans) ans=-1;
        }

        return ans;
    }
};