class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
           sort(arr.begin(),arr.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
           });
              
             int i=1;
          int prevIdx=0;
          int cnt=1;
          while(i<arr.size()){
            
              int currL=arr[i][0];
              int currR=arr[i][1];
              if(currL>=arr[prevIdx][0] && currR<=arr[prevIdx][1]) i++;
              else{
                 prevIdx=i;
                 cnt++;
                i++;
              }
          }

          return cnt;
   
    }
};