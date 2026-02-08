class Solution {
public:
    long long maximumScore(vector<int>& arr) {
  int n=arr.size();
        vector<long long>sum(n);
        sum[0]=arr[0];
        for(int i=1;i<n;i++) sum[i]=arr[i]+sum[i-1];

       vector<int>sf(n);
        long long mine=1e15;
        for(int i=n-1;i>=0;i--){
            mine=min(mine,(long long)arr[i]);
            sf[i]=mine;
        }

        long long ans=-1e15;
        for(int i=0;i<=n-2;i++){
             ans=max(ans,sum[i]-sf[i+1]);
        }
        cout << ans << endl;
        return ans;
    }
};