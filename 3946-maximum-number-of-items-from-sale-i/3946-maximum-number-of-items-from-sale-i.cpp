class Solution {
public:
    int dp[1001][1501];
    int solve(int idx,int bud,vector<vector<int>>&arr){
        if(idx>=arr.size() || bud<=0) return 0;

        //take once or infinite
        
        if(dp[idx][bud]!=-1) return dp[idx][bud];
        int ans=0;
        
       if(bud-arr[idx][0]>=0) ans=max(ans,1+solve(idx,bud-arr[idx][0],arr));
        if(bud-arr[idx][0]>=0) ans=max(ans,1+arr[idx][1]+solve(idx+1,bud-arr[idx][0],arr));
      //skip
        ans=max(ans,solve(idx+1,bud,arr)); 

        return dp[idx][bud]=ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         int n=items.size();
        vector<vector<int>>arr(n,vector<int>(2));

        for(int i=0;i<n;i++){
            int divisor=items[i][0];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(items[j][0]%divisor==0) cnt++;
            }
            arr[i][0]=items[i][1];
            arr[i][1]=cnt;
        }

        // arr-> price,free
     memset(dp,-1,sizeof(dp));
        return solve(0,budget,arr);
    }
};