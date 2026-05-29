class Solution {
public:
    int minElement(vector<int>& arr) {
            
            int ans=INT_MAX;

            for(int i=0;i<arr.size();i++){
                int n=arr[i];
                int sum=0;
                while(n>0){
                    sum+=(n%10);
                    n/=10;
                }
                ans=min(ans,sum);
            }

            return ans;
    }
};