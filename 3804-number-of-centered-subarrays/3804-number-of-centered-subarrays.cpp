class Solution {
public:
    int centeredSubarrays(vector<int>& arr) {
          set<int>st;
    int cnt=0;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                st.insert(arr[j]);
                sum+=arr[j];
                if(st.find(sum)!=st.end()) cnt++;
            }
            st.clear();
        }
        cout << cnt << endl;
        return cnt;
    }
};