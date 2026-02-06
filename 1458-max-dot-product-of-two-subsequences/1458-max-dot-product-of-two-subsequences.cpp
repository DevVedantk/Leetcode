class Solution {
public:
int dp[501][501][2];
int solve(int idx1,int idx2,int len,vector<int>& arr1,vector<int>& arr2){
    if(idx1>=arr1.size() || idx2>=arr2.size()){
      if(len==1) return 0;
        return -1e7;
    }
    if(dp[idx1][idx2][len]!=-1e7) return dp[idx1][idx2][len];
    int ans=-1e7;
   if(idx1<arr1.size() && idx2<arr2.size()) ans=max(ans,(arr1[idx1]*arr2[idx2])+solve(idx1+1,idx2+1,1,arr1,arr2));
   if(idx1+1<arr1.size()) ans=max(ans,solve(idx1+1,idx2,len,arr1,arr2));
   if(idx2+1<arr2.size()) ans=max(ans,solve(idx1,idx2+1,len,arr1,arr2));
    ans=max(ans,solve(idx1+1,idx2+1,len,arr1,arr2));
    return dp[idx1][idx2][len]=ans;
}
    int maxDotProduct(vector<int>& arr1, vector<int>& arr2) {
         for(int i=0;i<=500;i++){
            for(int j=0;j<=500;j++){
                for(int k=0;k<=1;k++){
                    dp[i][j][k]=-1e7;
                }
            }
         }
        return solve(0,0,0,arr1,arr2);
    }
};