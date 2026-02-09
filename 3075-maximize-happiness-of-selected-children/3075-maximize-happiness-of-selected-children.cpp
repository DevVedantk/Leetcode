class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
          
          sort(hap.begin(),hap.end());
          reverse(hap.begin(),hap.end());

          int i=0;
          long long ans=0;
          while(k>0 && i<hap.size()){
           if(hap[i]-i>=0) {hap[i]-=i;
            ans+=hap[i];}
            i++;  k--;
          }
   return ans;
    }
};