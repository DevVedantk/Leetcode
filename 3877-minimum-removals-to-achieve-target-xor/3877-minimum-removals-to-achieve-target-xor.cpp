class Solution {
public:
    int dp[50][20001];
    int solve(vector<int>&arr,int idx,int target,int currXor){
        if(idx>=arr.size()){
            if(currXor==target) return 0;
            return INT_MIN;
        }

        if(dp[idx][currXor]!=-1) return dp[idx][currXor];
        int ans=INT_MIN;

        ans=max(ans,solve(arr,idx+1,target,currXor)); //skip
        ans=max(ans,1+solve(arr,idx+1,target,currXor^arr[idx])); //take

        return dp[idx][currXor]=ans;
        
    }
    int minRemovals(vector<int>& arr, int target) {
        memset(dp,-1,sizeof(dp));
             
        int len=solve(arr,0,target,0);
        if(len<0) return -1;
        
        return (arr.size()-len);
    }
};