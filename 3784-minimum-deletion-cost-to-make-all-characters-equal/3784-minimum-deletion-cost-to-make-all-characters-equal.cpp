class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

       int n=s.size();
        long long tot=0;
        for(int i=0;i<n;i++) tot+=cost[i];
        map<char,long long>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]+=cost[i];
        }

        long long ans=1e15;
        for(auto ele:mp){
           ans=min(ans,tot-ele.second);  
        }
        cout << ans << endl;
        return ans;
        
        
    }
};