class Solution {
public:
    int minimumCost(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=0;
         int n=arr.size();
         

        for(int i=n-1;i>=0;i-=3){
             ans+=arr[i];
            if(i-1>=0) ans+=arr[i-1];
        }

        return ans;
    }
};