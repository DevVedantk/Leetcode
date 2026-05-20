class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>mp;
        int cnt=0;
     vector<int>ans(A.size());
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;mp[B[i]]++;
            if(mp[A[i]]==2) cnt++;
            if(A[i]!=B[i] && mp[B[i]]==2) cnt++;
            ans[i]=cnt;
        }

        return ans;
    }
};