class Solution {
public:
int MOD=1e9+7;
int n,m;
map<pair<int,int>,pair<long long,long long>>dp;
pair<long long,long long> solve(int row,int col,vector<vector<int>>&arr){
    if(row==m-1 && col==n-1){
       int val=arr[row][col];
       return {val,val};
    }
    if(row>=m || col>=n){
        return {-1e9,-1e9};
    }
     
   auto pair=make_pair(row,col);
   if(dp.find(pair)!=dp.end()) return dp[pair];

    long long currMx=LLONG_MIN,currMn=LLONG_MAX;
    int val=arr[row][col];
    
    if(row+1<m && col<n){
        auto [mx,mn]=solve(row+1,col,arr);
        currMx=max({currMx,val*mn,val*mx});
        currMn=min({currMn,val*mn,val*mx});
    }
    if(col+1<n && row<m) { 
      auto [mx,mn]=solve(row,col+1,arr);
        currMx=max({currMx,val*mn,val*mx});
        currMn=min({currMn,val*mn,val*mx});
    }
    return dp[pair]={currMx,currMn};
}
    int maxProductPath(vector<vector<int>>& grid) {
          m=grid.size();
          n=grid[0].size();
          
         
          auto [mx,mn]=solve(0,0,grid);
          return  mx<0 ? -1 : mx%MOD;
    }
};