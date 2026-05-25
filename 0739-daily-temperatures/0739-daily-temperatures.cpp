class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
         stack<pair<int,int>>st;
    st.push({arr[n-1],n-1});
    vector<int>ans(n);
    ans[n-1]=0;
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && st.top().first<=arr[i]){
            st.pop();
        }
        if(st.size()==0){
            ans[i]=0;
        } else ans[i]=st.top().second-i;
            
        st.push({arr[i],i});    
    }

    return ans;
    }
};