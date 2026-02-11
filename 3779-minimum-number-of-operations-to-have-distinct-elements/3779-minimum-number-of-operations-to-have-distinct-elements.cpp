class Solution {
public:
    int minOperations(vector<int>& arr) {
      set<int>st;
        int n=arr.size();
        int ans=0;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.find(arr[i])!=st.end()){
                int len=i+1;
                ans=(len+2)/3;
                break;
            } else st.insert(arr[i]);
        }
        // cout << ans << endl;
        return ans;
        
    }
};