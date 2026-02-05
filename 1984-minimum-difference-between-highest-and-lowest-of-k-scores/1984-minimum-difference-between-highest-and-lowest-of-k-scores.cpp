class Solution {
public:
    int minimumDifference(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++){
            ans=min(ans,arr[i+k-1]-arr[i]);
        }
        return ans;
         
    }
};