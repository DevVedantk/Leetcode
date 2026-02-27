class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int>sub;
            for(int j=0;j<nums.size();j++){
                if(((1<<j)&i)!=0) sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }

        return ans;
    }
};