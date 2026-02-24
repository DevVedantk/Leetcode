class Solution {
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=arr[n-1];
        
        for(int i=n-1;i>=(n-k);i--){
            int energy=arr[i];
            ans=max(ans,energy);
            int j=i-k;
            while(j>=0){
                energy+=arr[j];
                ans=max(ans,energy);
                j-=k;
            }
        }
       
       return ans;
    }
};