class Solution {
public:
int n,m;
int dp[71][71][71];
int solve(vector<vector<int>>& grid,int r1,int c1,int r2,int c2){
  if(r1>=n || c1>=m || r2>=n || c2>=m || c1<0 || c2<0) return -1e9;

      if (r1 == n - 1 && r2 == n - 1) {
            if (c1 == c2) return grid[r1][c1];
            return grid[r1][c1] + grid[r2][c2];
        }

        if(dp[c1][r2][c2]!=-1) return dp[c1][r2][c2]; 

  int ans=0;
  if(r1==r2 && c1==c2) ans+=grid[r1][c1];
   else ans+=grid[r1][c1] + grid[r2][c2];

   int f1=solve(grid,r1+1,c1,r2+1,c2);
   int f2=solve(grid,r1+1,c1+1,r2+1,c2+1);
   int f3=solve(grid,r1+1,c1-1,r2+1,c2-1);

   int f4=solve(grid,r1+1,c1-1,r2+1,c2);
   int f5=solve(grid,r1+1,c1-1,r2+1,c2+1);
  
    int f6=solve(grid,r1+1,c1+1,r2+1,c2-1);
   int f7=solve(grid,r1+1,c1,r2+1,c2-1);

   int f8=solve(grid,r1+1,c1,r2+1,c2+1);
   int f9=solve(grid,r1+1,c1+1,r2+1,c2);



   return dp[c1][r2][c2]=ans+max({f1,f2,f3,f4,f5,f6,f7,f8,f9});
}

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0,grid[0].size()-1);
    }
};