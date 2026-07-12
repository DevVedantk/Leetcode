class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mp;

        for(int i=0;i<arr.size();i++) mp[arr[i]].push_back(i);

        sort(arr.begin(),arr.end());
        vector<int>ans(arr.size());

        int i=0;
        int rank=1;
        while(i<arr.size()){
            while(i+1<arr.size() && arr[i]==arr[i+1]) i++;
            vector<int>&brr=mp[arr[i]];

            for(int idx:brr) ans[idx]=rank;
            rank++;
            i++;
        }

        return ans;

    }
};