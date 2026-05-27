class Solution {
public:
using ll=long long;
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& q) {
         int n=nums2.size();
        int len=ceil(sqrt(n));
        vector<ll>arr(nums2.begin(),nums2.end());
        vector<unordered_map<ll,ll>>mp(len);
        vector<ll>lazy(len,0);
         
       for(int i=0;i<arr.size();i++){
           mp[i/len][arr[i]]++;
       }
        
        vector<int>ans;

        for(int i=0;i<q.size();i++){
              if(q[i].size()==4){
                     //update query
                     int l=q[i][1],r=q[i][2];
                     ll val=q[i][3];

                     while(l%len!=0 && l<=r){
                        mp[l/len][arr[l]]--;
                        arr[l]=arr[l]+val;
                        mp[l/len][arr[l]]++;
                        l++;
                     }

                     while((r+1)%len!=0 && l<=r){
                        mp[r/len][arr[r]]--;
                        arr[r]=arr[r]+val;
                        mp[r/len][arr[r]]++;
                        r--;
                     }
                     if(l<r){
                     for(int j=l/len;j<=r/len;j++){
                        lazy[j]+=val;
                     }
                     }
              } else{
                    
                    int cnt=0;
                    int tot=q[i][1];
                    for(int j=0;j<nums1.size();j++){
                        int idx=0;
                         for(auto &e:mp){
                            if(e.find(tot-nums1[j]-lazy[idx])!=e.end()) cnt+=e[(tot-nums1[j]-lazy[idx])];
                            idx++;
                         }
                    }
                    ans.push_back(cnt);
              }
        }
        
        return ans;
    }
};