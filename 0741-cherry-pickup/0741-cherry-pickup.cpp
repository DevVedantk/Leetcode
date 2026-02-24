class Solution {
public:
int n;
int dp[51][51][51][51];
int solve(vector<vector<int>>& grid,int r1,int c1,int r2,int c2){
   if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) 
    return -1e9;
  
  if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
  if(r1==n-1 && c1==n-1) return grid[r1][c1];

  
   int ans=0;
   if(r1==r2 && c1==c2) ans+=grid[r1][c1];
   else ans= ans + grid[r1][c1] + grid[r2][c2];
   
   int f1 = solve(grid,r1+1,c1,r2+1,c2); 
   int f2 = solve(grid,r1,c1+1,r2,c2+1); 
   int f3 = solve(grid,r1+1,c1,r2,c2+1); 
   int f4 = solve(grid,r1,c1+1,r2+1,c2); 
   return dp[r1][c1][r2][c2]=ans+max({f1,f2,f3,f4});
}

int cherryPickup(vector<vector<int>>& grid) {
     n=grid.size();
     memset(dp,-1,sizeof(dp));
       int ans=solve(grid,0,0,0,0); 
       return ans<0?0:ans;
    }
};