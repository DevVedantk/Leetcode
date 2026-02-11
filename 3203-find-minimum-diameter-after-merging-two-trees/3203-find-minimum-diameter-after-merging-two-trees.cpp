class Solution {
public:
vector<int>depth;
void dfs(int node,int parent,vector<vector<int>>& adj){
      for(int child:adj[node]){
          if(child==parent) continue;
          depth[child]=1+depth[node];
          dfs(child,node,adj);
      }
} 

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n=edges1.size()+1 , m=edges2.size()+1;
        vector<vector<int>>adj1(n);  
        vector<vector<int>>adj2(m);

        for(int i=0;i<edges1.size();i++){
            int a=edges1[i][0],b=edges1[i][1];
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }  

         for(int i=0;i<edges2.size();i++){
            int a=edges2[i][0],b=edges2[i][1];
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        } 

        depth.assign(n,0);

        dfs(0,-1,adj1);
        int maxd=-1,maxnode=0;
        for(int i=0;i<depth.size();i++){
            if(depth[i]>=maxd){
                maxd=depth[i];
                maxnode=i;
            }
            depth[i]=0;
        }

        dfs(maxnode,-1,adj1);
        int dia1=0;
        for(int i=0;i<depth.size();i++) dia1=max(dia1,depth[i]);


        depth.assign(m,0);

        dfs(0,-1,adj2);
         maxd=-1,maxnode=0;
        for(int i=0;i<depth.size();i++){
            if(depth[i]>=maxd){
                maxd=depth[i];
                maxnode=i;
            }
             depth[i]=0;
        }

        dfs(maxnode,-1,adj2);
        int dia2=0;
        for(int i=0;i<depth.size();i++) dia2=max(dia2,depth[i]);
    

        int ans=(dia1+1)/2+(dia2+1)/2+1;
        cout << dia1 << " " << dia2 << endl;
        // ans=max(ans,max(dia1,dia2));
        return max({ans,dia1,dia2});



    }
};