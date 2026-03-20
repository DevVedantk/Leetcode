class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>());
        // cout << ans.size() << endl;
        //  int r=0,c=0;
        // for(int i=0;i<ans.size();i++){
        //     for(int j=0;j<ans[0].size();j++) cout << ans[i][j] << " ";
        //     cout << endl;
        // }
        for(int i=0;i<=grid.size()-k;i++){
            for(int j=0;j<=grid[0].size()-k;j++){
            set<int>st;
                
                vector<int>arr;
                for(int a=i;a<i+k;a++){
                    for(int b=j;b<j+k;b++){
                        st.insert(grid[a][b]);
                    }
                }

                for(auto ele:st) arr.push_back(ele);
                int mn=INT_MAX;
                for(int c=1;c<arr.size();c++){
                    mn=min(mn,abs(arr[c]-arr[c-1]));
                }
                if(st.size()==1) mn=0;
               ans[i].push_back(mn);
            }
        }
        return ans;
    }
};