class Solution {
public:
int dp[21][21];
int solve(vector<int>& arr,int i,int j){
     if(i>j){
        return 0;
     }
     if(i==j) return arr[i];
      if(dp[i][j]!=-1) return dp[i][j]; 

     int ans=0;

     int left=arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1));
     int right=arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1));
     ans=max(left,right);

     return dp[i][j]=ans;
}
    bool predictTheWinner(vector<int>& arr) {
         int t=0;
         for(int ele:arr) t+=ele;
       memset(dp,-1,sizeof(dp));
        int p1score=solve(arr,0,arr.size()-1);
        return p1score>=(t-p1score);
    }
};