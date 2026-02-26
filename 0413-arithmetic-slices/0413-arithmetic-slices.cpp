class Solution {
public:

int dp[5001];
bool check(vector<int>& arr,int lo,int hi){
    // cout << lo << " " << hi << endl;
    if((hi-lo+1)<=2) return false;
    int diff=arr[lo+1]-arr[lo];
    for(int i=lo+2;i<=hi && i<arr.size();i++){
        if(diff!=(arr[i]-arr[i-1])) return false;
    }
    //   cout << "pass " << lo << " " << hi << endl;
    return true;
}
int solve(vector<int>& arr,int start){
    if(start>=arr.size()) return 0;
    
    int ans=0;
     
     if(dp[start]!=-1) return dp[start];
    for(int end=start;end<arr.size();end++){
        if(check(arr,start,end))
         ans++;
    }
   ans+=solve(arr,start+1);
    return dp[start]=ans;

}
    int numberOfArithmeticSlices(vector<int>& arr) {
          memset(dp,-1,sizeof(dp));
        return solve(arr,0);
        
    }
};