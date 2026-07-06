class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
           sort(arr.begin(),arr.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
           });
              
               

          vector<pair<int,int>>brr;
          brr.push_back({arr[0][0],arr[0][1]});

          int i=1;
          while(i<arr.size()){
               auto [prevL,prevR]=brr[brr.size()-1];
              int currL=arr[i][0];
              int currR=arr[i][1];
              if(currL>=prevL && currR<=prevR) i++;
              else{
                brr.push_back({currL,currR});
                i++;
              }
          }

          return brr.size();
   
    }
};