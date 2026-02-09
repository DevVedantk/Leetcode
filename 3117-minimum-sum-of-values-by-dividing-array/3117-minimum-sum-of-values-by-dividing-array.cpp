class Solution {
public:

vector<vector<unordered_map<int,int>>>dp;
int solve(vector<int>&arr,vector<int>&andv,int i,int j,int andval){
    if(i>=arr.size()){
        if(j>=andv.size()) return 0;
        return 1e9;
    }
    if(j>=andv.size()) return 1e9;
    
    if(dp[i][j].find(andval)!=dp[i][j].end()) return dp[i][j][andval];

    int take=1e9;
    if((andval & arr[i])==andv[j]){
        take=arr[i]+solve(arr,andv,i+1,j+1,(1<<17)-1);
    }
    int skip=solve(arr,andv,i+1,j,arr[i]&andval);
    
    return dp[i][j][andval]=min(take,skip);
}
    int minimumValueSum(vector<int>& arr, vector<int>& andv) {
         int n=arr.size();
        dp.assign(n+1,vector<unordered_map<int,int>>(11));
        int res=solve(arr,andv,0,0,(1<<17)-1);
      return res==1e9 ? -1 : res;
    }
};