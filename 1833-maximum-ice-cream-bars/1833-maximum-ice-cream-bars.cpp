class Solution {
public:
    int maxIceCream(vector<int>& arr, int coins) {
         sort(arr.begin(),arr.end());

         int cnt=0;

         for(int i=0;i<arr.size();i++){
            if(coins>=arr[i]){
                cnt++;
                coins-=arr[i];
            } else break;
         }

         return cnt;
    }
};