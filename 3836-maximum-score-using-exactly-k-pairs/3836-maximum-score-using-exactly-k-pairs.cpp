class Solution {
public:
long long dp[101][101][101];
const long long NEG = LLONG_MIN / 2;
long long solve(vector<int>&arr1,vector<int>&arr2,int k,int i,int j){
      if(arr1.size() - i < k || arr2.size() - j < k)
        return NEG;

    if(i>=arr1.size() || j>=arr2.size()){
        if(k==0) return 0;
        return NEG;
    }
    if(k==0) return 0;
    
    long long ans=NEG;
    
    if(dp[i][j][k]!=NEG) return dp[i][j][k];
    ans=max(ans,solve(arr1,arr2,k,i+1,j));
    ans=max(ans,solve(arr1,arr2,k,i,j+1));
    ans=max(ans,((long long)arr1[i]*(long long)arr2[j])+solve(arr1,arr2,k-1,i+1,j+1));
    return dp[i][j][k]=ans; 
    
}
    long long maxScore(vector<int>& arr1, vector<int>& arr2, int k) {
        
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                for(int l=0;l<=100;l++) dp[i][j][l]=NEG;
            }
        }
        return solve(arr1,arr2,k,0,0);
    }
};