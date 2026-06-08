class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        vector<int>arr;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(p==nums[i]) cnt++;
            if(nums[i]<p){
                arr.push_back(nums[i]);
            }
        }

        vector<int>ans;
        for(int i=0;i<arr.size();i++) ans.push_back(arr[i]);
        for(int i=0;i<cnt;i++)ans.push_back(p);

        for(int i=0;i<nums.size();i++) {
            if(nums[i]>p) ans.push_back(nums[i]);
        }

        return ans;

    }
};