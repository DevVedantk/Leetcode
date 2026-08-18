class Solution {
public:
    int largestInteger(vector<int>& arr, int k) {
        map<int,int>mp;
        int mis=-1;
        int mx=0;
        for(int ele:arr) {
            mp[ele]++;
            mx=max(mx,ele);
        }
        for(auto e:mp){
            if(e.second==1) mis=max(mis,e.first);
        }

        if(k==arr.size() || k==1){
            if(k==arr.size()) return mx;
           return mis;
        } else {
           mis= mp[arr[0]]==1 ? arr[0] : -1;
          int mis2=mp[arr[arr.size()-1]]==1 ? arr[arr.size()-1] : -1;
         
          return max(mis,mis2);
        }
    }
};