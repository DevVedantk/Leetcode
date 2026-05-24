class Solution {
public:
    int dp[1001];
    int solve(int idx,vector<int>&arr,int d){
        int n=arr.size();
    
        if(dp[idx]!=-1) return dp[idx];
        int ans=1;
        for(int i=idx-1;i>=0 && i>=idx-d;i--){
            if(arr[i]<arr[idx]) ans=max(ans,1+solve(i,arr,d));
            else break;
        }
        
        for(int i=idx+1;i<n && i<=idx+d;i++){
            if(arr[i]<arr[idx]) ans=max(ans,1+solve(i,arr,d));
            else break;
        }

        return dp[idx]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans=0;

        for(int i=0;i<arr.size();i++){
            memset(dp,-1,sizeof(dp));
            ans=max(ans,solve(i,arr,d));
        }

        return ans;
    }
};