class Solution {
public:
    long long countStableSubarrays(vector<int>& c) {
        int n=c.size();
        vector<long long>pref(n+1,0);

        for(int i=1;i<=c.size();i++){
            pref[i]=pref[i-1]+c[i-1];
        }
        long long ans=0;
        map<pair<long long,long long>,long long>mp;
        for(int r=3;r<=n;r++){
            long long target=pref[r]-2LL*c[r-1];
            mp[{pref[r-2],c[r-3]}]++;
            ans+=mp[{target,c[r-1]}];
        }
        return ans;


    }
};