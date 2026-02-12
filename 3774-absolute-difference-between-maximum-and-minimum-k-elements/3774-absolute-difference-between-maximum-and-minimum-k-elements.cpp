class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
    int s1=0,s2=0;
        for(int i=0;i<k;i++) s1+=nums[i];
        int n=nums.size();
        for(int i=n-1;i>=n-k;i--) s2+=nums[i];

        cout << abs(s1-s2) << endl;
        return abs(s1-s2);
    } 
};