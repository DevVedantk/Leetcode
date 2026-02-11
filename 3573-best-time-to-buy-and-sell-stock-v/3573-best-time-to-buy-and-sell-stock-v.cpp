class Solution {
public:
long long dp[501][1001][4];
long long solve(vector<int>& prices,int k,int idx,int type){
      if(idx>=prices.size() || k==0){
        if(type==2) return 0;
        return -1e15;
      }
      long long profit=-1e9;

     if(dp[k][idx][type]!=-1) return dp[k][idx][type]; 
      if(type==2){
        //purchasing stock on current day and decide type of transaction
           profit=max(profit,solve(prices,k,idx+1,1)-prices[idx]); //1 means normal tractions
           profit=max(profit,solve(prices,k,idx+1,0)+prices[idx]); //0 means short tractions
      } else{
        //want to sell on this day
        if(type==1){
            //here after selling type doesn't even matter 
           profit=max(profit,(prices[idx])+solve(prices,k-1,idx+1,2));
        } else if(type==0){
            //here after selling type doesn't even matter 
            profit=max(profit,-prices[idx]+solve(prices,k-1,idx+1,2));
        }
      }
    profit=max(profit,solve(prices,k,idx+1,type));
   
   return dp[k][idx][type]=profit;
}

long long maximumProfit(vector<int>& prices, int k) {
     memset(dp,-1,sizeof(dp));
       return solve(prices,k,0,2); 
    }
};