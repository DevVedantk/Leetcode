class Solution {
public:
    int countDistinct(vector<int>& arr, int k, int p) {
        int ans=0;
        set<vector<int>>st;
        for(int i=0;i<arr.size();i++){
             int cnt=0;
             vector<int>brr;
            for(int j=i;j<arr.size();j++){
               if(arr[j]%p==0) cnt++;
               if(cnt<=k){
                brr.push_back(arr[j]);
                st.insert(brr);
               } else break;
            }
        }
        return st.size();
    }
};