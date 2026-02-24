class Solution {
public:
int dp[20001];
int solve(vector<pair<int,int>>& arr,int idx){
    if(idx>=arr.size()) return 0;
   
   if(dp[idx]!=-1) return dp[idx];
    int ans=0;
    int idx2=idx+1;

    while(idx2<arr.size() && arr[idx2].first<=arr[idx].first+1) idx2++;
    ans=max(ans,arr[idx].second+solve(arr,idx2));

    ans=max(ans,solve(arr,idx+1));

    return dp[idx]=ans;
}
    int deleteAndEarn(vector<int>& brr) {
      map<int,int>mp;
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<brr.size();i++) mp[brr[i]]+=brr[i];
      vector<pair<int,int>>arr;

      for(auto ele:mp) arr.push_back({ele.first,ele.second});
      sort(arr.begin(),arr.end());   
      return solve(arr,0);  
    }
};