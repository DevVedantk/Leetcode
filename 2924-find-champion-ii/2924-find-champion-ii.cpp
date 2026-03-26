class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>in(n,0);

        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            in[b]++;
        }

        int ans=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
           if(in[i]==0){
            cnt++;
            ans=i;
           }
        }

        return cnt>1 ? -1 : ans;
    }
};