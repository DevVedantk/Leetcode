class Solution {
public:
    int sortPermutation(vector<int>& arr) {
        int k=~0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i) k=k&arr[i];
          
        }
        if(k==-1) return 0;

        return k;
    }
};