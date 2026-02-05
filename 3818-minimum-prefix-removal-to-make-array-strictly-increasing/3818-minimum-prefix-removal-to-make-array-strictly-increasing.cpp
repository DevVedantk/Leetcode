class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int idx=-1;
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i-1]>=nums[i]){
                idx=i-1;
                break;
            }
        }
        // cout << idx-0+1 << endl;
         if(idx==-1) return 0;
        return idx+1;
    }
};