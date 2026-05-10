class Solution {
public:
int dp[1001][1001];
    int solve(vector<int>&arr,int idx,int prevIdx,int target){
        if(idx==arr.size()-1){
             if((arr[idx]-arr[prevIdx])<=target && (arr[idx]-arr[prevIdx])>=(-1*target)){
                 return 1;
            }
            return -1e9;
        }

        int ans=-1e9;
     if (prevIdx!=-1 && dp[idx][prevIdx]!=-1) return dp[idx][prevIdx];
        if(prevIdx==-1) ans=max(ans,solve(arr,idx+1,idx,target));
        else{
            if((arr[idx]-arr[prevIdx])<=target && (arr[idx]-arr[prevIdx])>=(-1*target)){
                ans=max(ans,1+solve(arr,idx+1,idx,target));
            }
            ans=max(ans,solve(arr,idx+1,prevIdx,target));  
        }
        
        if(prevIdx==-1) return ans;
        return dp[idx][prevIdx]=ans;

    } 

    int maximumJumps(vector<int>& arr, int target) {
           memset(dp,-1,sizeof(dp));
          int ans=solve(arr,0,-1,target);
          if(ans<=0) return -1;
          return ans;
    }
};