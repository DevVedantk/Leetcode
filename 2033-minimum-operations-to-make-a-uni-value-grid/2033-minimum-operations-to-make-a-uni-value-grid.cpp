class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        bool check=false;
         vector<int>arr;
         int same=-1;
         bool dup=false;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                 arr.push_back(grid[i][j]);
                //  if(same==-1) same=grid[i][j];
                //  else if(same!=-1 && grid[i][j]!=same) dup=true;
            }
         }
    //   if(!dup) return 0;

         sort(arr.begin(),arr.end());
         int n=arr.size();
         int mid=arr[n/2];
        
        int ans=0;
        cout << mid << endl;
         for(int i=0;i<arr.size();i++){
            int df=abs(arr[i]-mid);
            if(df%x!=0) return -1;
            ans=ans+(df/x);
         }

         return ans;
          
    }
};