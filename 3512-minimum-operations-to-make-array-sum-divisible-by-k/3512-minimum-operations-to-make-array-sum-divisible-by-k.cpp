class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        int sum=0;
        for(int ele:arr) sum+=ele;

        return sum%k;
    }
};