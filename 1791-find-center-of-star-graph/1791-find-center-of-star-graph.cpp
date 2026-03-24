class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
         vector<int>out(n+2);

         for(int i=0;i<n;i++){
            int a=edges[i][0],b=edges[i][1];
            out[a]++;out[b]++;
         }

         for(int i=1;i<out.size();i++){
            if(out[i]==n) return i;
         }
         return 0;
    }
};