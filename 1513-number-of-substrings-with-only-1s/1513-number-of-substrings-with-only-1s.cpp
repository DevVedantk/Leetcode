class Solution {
public:
    int numSub(string s) {
        int i=0,j=0;
         int n=s.size();
         int MOD=1e9+7;
        int ans=0;
       while(j<s.size()){
          if(s[j]=='0') j++;
          else{
            int cnt=0;
            while(j<n && s[j]=='1'){
                cnt++;
                j++;
            }
            ans=(ans+((1ll*cnt*(cnt+1))/2)%MOD)%MOD;
          }

       }
       return ans;
    }
};