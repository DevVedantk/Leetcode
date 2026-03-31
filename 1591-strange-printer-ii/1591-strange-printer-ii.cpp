class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n=targetGrid.size();
        int m=targetGrid[0].size();

        vector<int>minX(61,n),maxX(61,-1),minY(61,m),maxY(61,-1);
         set<int>st;

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int color=targetGrid[i][j];
                st.insert(color);

                minX[color]=min(minX[color],i);
                maxX[color]=max(maxX[color],i);
                minY[color]=min(minY[color],j);
                maxY[color]=max(maxY[color],j);
            }
         }
       int total=0;

   for(int ele:st) total=max(total,ele);

         vector<vector<int>>adj(total+1);
         vector<int>deg(total+1,0);
         for(int color:st){
            for(int i=minX[color];i<=maxX[color];i++){
                for(int j=minY[color];j<=maxY[color];j++){
                    if(targetGrid[i][j]!=color){
                        adj[color].push_back(targetGrid[i][j]);
                        deg[targetGrid[i][j]]++;
                    }
                }
            }
         }

         queue<int>q;

         for(int i=1;i<=total;i++){
            if(deg[i]==0) q.push(i);
         }

     int ans=0;
         while(q.size()>0){
            auto node=q.front();
            q.pop();
            ans++;

            for(int child:adj[node]){
                deg[child]--;
                if(deg[child]==0) q.push(child);
            }
         }

         return (ans==total);
    }
};