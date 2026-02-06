class Solution {
public:
    int minRemoval(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            long long maxe=(long long)arr[i]*k;
            auto it=upper_bound(arr.begin(),arr.end(),maxe);
            int idx=it-arr.begin();
           ans=min(ans,i+(n-idx));
        }
        return ans;
    }
};