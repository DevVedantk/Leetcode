class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> mp;

         int n=grid.size();
         for(int i=0;i<n;i++){
            vector<int>sum(n,0);
            sum[0]=grid[i][0];
            for(int j=1;j<n;j++){
                sum[j]=sum[j-1]+grid[i][j];
            }
            mp[i]=sum;
         }

         int op=0;
         
         for(int targetIdx=0;targetIdx<n;targetIdx++){
            //check valid row 
             int l=targetIdx+1,r=n-1;
             int validIdx=-1;
             for(int j=targetIdx;j<n;j++){
                 if ((mp[j][r] - mp[j][l - 1]) == 0) {
                 validIdx = j;
                break;
                 }
              }
             if(validIdx==-1) return -1;
             op+=(validIdx-targetIdx);
             
            //  mp[]
             int returnIdx=validIdx-1;
              unordered_map<int,vector<int>> new_mp;

             for (auto &p : mp) {
                if(p.first<validIdx) new_mp[p.first + 1] = p.second;
              }
             vector<int> it = mp[validIdx];  
             new_mp[targetIdx] = it;

               for (auto &p : mp) {
                if(p.first>validIdx) new_mp[p.first] = p.second;
              }
              mp=new_mp;

         }

         return op;
    }
};