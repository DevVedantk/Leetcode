class Solution {
public:
    int minPairSum(vector<int>& arr) {
        int n=1e5+1;
        vector<int>freq(n,0);
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++; 
        }

        int i=0,j=n-1;
   int ans=0;
        while(i<=j){
           if(freq[i]==0) i++;
           if(freq[j]==0) j--;
           
           if(freq[i]>0 && freq[j]>0){
           ans=max(ans,i+j);
           freq[i]--;
           freq[j]--;
           }
        }
        return ans;

    }
};