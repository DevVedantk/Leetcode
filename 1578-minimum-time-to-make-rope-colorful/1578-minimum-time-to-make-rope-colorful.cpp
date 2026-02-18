class Solution {
public:
    int minCost(string s, vector<int>& need) {
        int n=need.size();
        vector<int>pref(n,0);
        pref[0]=need[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+need[i];

         int ans=0;
         int i=0,j=0;
         int maxele=-1e9;
         while(j<s.size()){
             if(s[i]==s[j]){
                 maxele=max(maxele,need[j]);
                 j++;
             }
             else{
                int sum=0;
                if(i-1>=0) sum=pref[j-1]-pref[i-1];
                else sum=pref[j-1];

                sum-=maxele;
                maxele=-1e9;
                ans+=sum;
                i=j;
             }
         }

          int sum=0;
                if(i-1>=0) sum=pref[j-1]-pref[i-1];
                else sum=pref[j-1];

                sum-=maxele;
                ans+=sum;

         return ans;
    }
};