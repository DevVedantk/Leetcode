class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            vector<int>dig;
            while(n>0){
                int d=n%10;
                dig.push_back(d);
                n/=10;
            }

            reverse(dig.begin(),dig.end());
            for(int ele:dig) ans.push_back(ele);
        }

        return ans;
    }
};