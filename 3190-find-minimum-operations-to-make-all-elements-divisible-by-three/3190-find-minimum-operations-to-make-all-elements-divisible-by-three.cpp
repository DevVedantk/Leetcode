class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<=20;i++){
            st.insert(3*i);
        }
        
        int cnt=0;
        for(int i=0;i<nums.size();i++){
         auto ub=st.lower_bound(nums[i]);
         int steps=(*ub-nums[i]);
          ub--;
          if(ub!=st.end()) steps=min(steps,nums[i]-*ub);
          cnt+=steps;
        }
return cnt;
    }
};