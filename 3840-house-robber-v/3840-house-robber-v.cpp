class Solution {
public:
long long dp[100001];
    long long solve(int idx,vector<int>& arr, vector<int>& col){
        if(idx>=arr.size()) return 0;
        long long ans=0;
      int n=arr.size();

        if(dp[idx]!=-1) return dp[idx];
        ans = solve(idx + 1, arr, col);

      
        long long take = arr[idx];

       
        if (idx + 1 < arr.size() && col[idx] == col[idx + 1]) {
            take += solve(idx + 2, arr, col);
        } else {
            take += solve(idx + 1, arr, col);
        }

        ans = max(ans, take);

        return dp[idx] = ans;
    }
    long long rob(vector<int>& arr, vector<int>& col) {
        memset(dp,-1,sizeof(dp));
        return solve(0,arr,col);
    }
};