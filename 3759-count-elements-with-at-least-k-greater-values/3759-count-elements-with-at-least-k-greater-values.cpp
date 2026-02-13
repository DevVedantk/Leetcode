class Solution {
public:
    int countElements(vector<int>& arr, int k) {
          sort(arr.begin(),arr.end());
  int cnt=0;
        
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            int key=arr[i];
            int low=i+1,hi=n-1;
           int idx=n;
            while(low<=hi){
                int mid=(low+hi)/2;
                if(arr[mid]>key){
                     hi=mid-1;
                    idx=mid;
                }
                else low=mid+1;
            }
            if(n-idx>=k) cnt++;
        }
        return cnt;

    }
};