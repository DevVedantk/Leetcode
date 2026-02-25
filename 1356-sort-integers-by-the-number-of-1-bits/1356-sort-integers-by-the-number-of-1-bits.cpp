class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
         map<int,vector<int>>mp;
         sort(arr.begin(),arr.end());

         for(int i=0;i<arr.size();i++){
            int n=arr[i];
            int cnt=0;
            while(n>0){
                if(n%2!=0) cnt++;
                n>>=1;
            }
            mp[cnt].push_back(arr[i]);
         }
         
         vector<int>ans;
         for(auto ele:mp){
            for(int i=0;i<ele.second.size();i++) ans.push_back(ele.second[i]);
         }
         return ans;

    }
};