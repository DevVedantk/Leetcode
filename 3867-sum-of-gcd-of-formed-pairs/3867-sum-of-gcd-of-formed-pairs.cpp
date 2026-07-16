class Solution {
public:
    long long gcdSum(vector<int>& nums) {
          
          int n=nums.size();
          vector<int>pref(n);
          
          int mx=0;
          for(int i=0;i<nums.size();i++){
             mx=max(mx,nums[i]);
             pref[i]=gcd(nums[i],mx);
          }

          sort(pref.begin(),pref.end());
          long long ans=0;

          int i=0,j=n-1;

          while(i<j){
            ans+=gcd(pref[i],pref[j]);
            i++;
            j--;
          }

          return ans;
    }
};