class Solution {
public:
long long dp[100001];
long long solve(vector<pair<int,long long>>& arr,int idx){
    if(idx>=arr.size()) return 0;
     
     if(dp[idx]!=-1) return dp[idx];
    long long ans=0;
     
   
     long long skip=solve(arr,idx+1);  

     int idx2=idx+1;
    while(idx2<arr.size() && arr[idx2].first<=arr[idx].first+2) idx2++;
    long long take=arr[idx].second+solve(arr,idx2); 

     
     ans=max(take,skip);

    // ans=max(ans,solve(arr,idx+1));

    return dp[idx]=ans;

}
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        map<int ,long long>mp;
        for(int i=0;i<power.size();i++) mp[power[i]]+=power[i];
        vector<pair<int,long long>>arr;
        for(auto ele:mp) arr.push_back({ele.first,ele.second});
    memset(dp,-1,sizeof(dp));
        return solve(arr,0);
    }
};