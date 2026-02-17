class Solution {
public:
int m,n;
int MOD=1e9+7;
// int dp[10001]
vector<vector<vector<int>>>dp;
int solve(vector<vector<int>>& grid,int row,int col,int k,int sum){
    if(row>=m || col>=n) return 0;
    if(row==m-1 && col==n-1){
        return ((grid[row][col]+sum)%k==0);
    }

if(dp[row][col][sum]!=-1) return dp[row][col][sum];

    int ans=0;
    
    ans=(ans+solve(grid,row+1,col,k,(sum+grid[row][col])%k))%MOD;
    ans=(ans+solve(grid,row,col+1,k,(sum+grid[row][col])%k))%MOD;
   
   return dp[row][col][sum]=ans;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(grid,0,0,k,0);
    }
};