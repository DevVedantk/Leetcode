class Solution {
public:
int dp[501][501][3];
int solve(int row,int col,int cnt,vector<vector<int>>&arr){
    if(row>=arr.size() || col>=arr[0].size()) return -1e9;
   if(row==arr.size()-1 && col==arr[0].size()-1) {
    if(arr[row][col] < 0 && cnt < 2) return 0;
    return arr[row][col];
}
    int ans=-1e9;

   if(dp[row][col][cnt]!=-1e9) return dp[row][col][cnt];
    int newp=arr[row][col];

     if(cnt<2){
     if(newp<0) ans=max(ans,solve(row+1,col,cnt+1,arr));
     if(newp<0) ans=max(ans,solve(row,col+1,cnt+1,arr));
     
    }
     ans=max(ans,newp+solve(row+1,col,cnt,arr));
      ans=max(ans,newp+solve(row,col+1,cnt,arr)); 

    return dp[row][col][cnt]=ans;

}
    int maximumAmount(vector<vector<int>>& coins) {
        for(int i=0;i<=500;i++){
            for(int j=0;j<=500;j++) {
                for(int k=0;k<=2;k++) dp[i][j][k]=-1e9;
            }
        }
        return solve(0,0,0,coins);
    }
};