class Solution {
public:
    int minimumIndex(vector<int>& arr, int ite) {

          int ans=INT_MAX;
        int idx=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=ite){
                if(arr[i]<ans){
                    ans=arr[i];
                    idx=i;
                }
            }
        }

        return idx;
        
    }
};