class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n=units.size();
        vector<vector<int>>arr(n,vector<int>(2));
        
        long long ans=0;
        if(units[0].size()==1){
           for(int i=0;i<n;i++){
            ans+=units[i][0];
           }
        return ans;
        }


        for(int i=0;i<units.size();i++){
            sort(units[i].begin(),units[i].end());
        }

        for(int i=0;i<units.size();i++){
            for(int j=0;j<2 && units[i].size();j++){
                arr[i][j]=units[i][j];
            } 
        }
         
         sort(arr.begin(),arr.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
         });

         ans=0;
          
          for(int i=n-1;i>=1;i--){
            ans+=arr[i][1];
            arr[0].push_back(arr[i][0]);
          }
        
        int mine=INT_MAX;
          for(int i=0;i<arr[0].size();i++){
            mine=min(mine,arr[0][i]);
          }
        ans+=mine;


      
        return ans;
    }
};