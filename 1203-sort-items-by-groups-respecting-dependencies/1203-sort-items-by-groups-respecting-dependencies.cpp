class Solution {
public:
vector<int> topological(vector<vector<int>>&adj,int n){
      
      vector<int>deg(n,0);
       queue<int>q;
       for(int i=0;i<adj.size();i++){
        for(int ele:adj[i]){
            deg[ele]++;
        }
       }
       for(int i=0;i<n;i++){
        if(deg[i]==0) q.push(i);
       }

       vector<int>res;

       while(q.size()>0){
        int node=q.front();
        q.pop();
        res.push_back(node);

        for(int child:adj[node]){
            deg[child]--;
            if(deg[child]==0){
                q.push(child);
            }
        }
       }

       return res;
}


vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        vector<vector<int>>adj1(n);

        for(int i=0;i<beforeItems.size();i++){
            for(int child:beforeItems[i]){
                adj1[child].push_back(i);
            }
        }

        vector<int>itemord=topological(adj1,n);
     
        if(itemord.size()!=n) return {};

       

         int g_cnt=INT_MIN;
         for(int i=0;i<group.size();i++){
            g_cnt=max(g_cnt,group[i]);
         }

         vector<int>ng(n);
         for(int i=0;i<n;i++){
            if(group[i]!=-1) ng[i]=group[i];
            else ng[i]=++g_cnt;
         }

           vector<vector<int>>adj2(g_cnt+1);
          for(int i=0;i<beforeItems.size();i++){
             for(int ele:beforeItems[i]){
                if(ng[ele]==ng[i]) continue;
               adj2[ng[ele]].push_back(ng[i]);
             }
          }
         
       
         vector<int>grpord=topological(adj2,g_cnt+1);
         if(grpord.size() != g_cnt+1) return {};

         map<int,int>mp;
         for(int i=0;i<grpord.size();i++){
            mp[grpord[i]]=i;
         }
          
          vector<vector<int>>ans(adj2.size());
          for(int ele:itemord){
              int g_no=ng[ele];
              ans[mp[g_no]].push_back(ele);
          }
       
        vector<int>list;
          for(int i=0;i<ans.size();i++) {
            for(int ele:ans[i]) list.push_back(ele);
          }

          return list;

    }
};