class Solution {
public:

int n,m;
int MOD=1e9+7;
int dp[301][301][16];
int solve(int r,int c,int k,int curr,vector<vector<int>>& grid){
    if(r==n-1 && c==m-1){
        curr=curr^grid[r][c];
        if(curr==k) return 1;
        return 0;
    }
    if(dp[r][c][curr]!=-1) return dp[r][c][curr];
       int ans=0;

     if(r+1<n) ans=(ans+solve(r+1,c,k,curr^grid[r][c],grid))%MOD;
     if(c+1<m) ans=(ans+solve(r,c+1,k,curr^grid[r][c],grid))%MOD;

     return dp[r][c][curr]=ans;
} 
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
           n=grid.size();
           m=grid[0].size();
           memset(dp,-1,sizeof(dp));

           return solve(0,0,k,0,grid);
    }
};