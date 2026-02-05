class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int diff=INT_MAX;
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=1;i<n;i++){
            diff=min(diff,arr[i]-arr[i-1]);
        }
     
     vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==diff) ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
    }
};