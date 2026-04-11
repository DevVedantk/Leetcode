class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]].push_back(i);


        int ans=INT_MAX;

        for(auto p:mp){
            vector<int>v=p.second;
            if(v.size()>=3){
                for(int i=1;i<v.size()-1;i++){
                    ans=min(ans,v[i]-v[i-1]+v[i+1]-v[i]+v[i+1]-v[i-1]);
                }
            }
        }

        return ans==INT_MAX ? -1 : ans;


    }
};