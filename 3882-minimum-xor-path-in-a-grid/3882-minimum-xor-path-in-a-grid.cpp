class Solution {
public:
    int n,m;
    vector<vector<vector<int>>>dp;
    int solve(int row,int col,vector<vector<int>>&grid,int xorv){
        if(row>=n || col>=m) return 1e9;
        if(row==n-1 && col==m-1){
            return grid[row][col]^xorv;
        }
        if(dp[row][col][xorv]!=-1) return dp[row][col][xorv];
      
         int ans=1e9;
        if(row+1<n) ans=min(ans,solve(row+1,col,grid,xorv^grid[row][col]));
         if(col+1<m) ans=min(ans,solve(row,col+1,grid,xorv^grid[row][col]));
      
        return dp[row][col][xorv]=ans;
    }
    int minCost(vector<vector<int>>& grid) {
     n=grid.size();
     
        m=grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return solve(0,0,grid,0);
    }
};