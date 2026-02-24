class Solution {
public:
 map<pair<int,int>,int>dp; 
int solve(int l,int r,vector<int>& cuts){
    if(l>r) return 0;
       
       auto pair=make_pair(l,r);
       if(dp.find(pair)!=dp.end()) return dp[pair];
      int ans=1e9;
     for(int k=l;k<=r;k++){
        int cost=solve(l,k-1,cuts)+solve(k+1,r,cuts)+(cuts[r+1]-cuts[l-1]);
        ans=min(ans,cost);
     }
     return dp[pair]=ans;

}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(1,cuts.size()-2,cuts);
    }
};