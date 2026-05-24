class Solution {
public:
        vector<int>path;
    map<int,vector<pair<int,int>>>adj;
    map<int,int>In,Out;
    vector<bool>seen;
     void dfs(int node){
            while(adj[node].size()>0){
                auto edges=adj[node].back();
                adj[node].pop_back();
                if(seen[edges.second]) continue;
                seen[edges.second]=true;
                dfs(edges.first);
            }
            path.push_back(node);
     }   
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
       for(int i=0;i<pairs.size();i++){
        int u=pairs[i][0],v=pairs[i][1];
         adj[u].push_back({v,i});
         Out[u]++;
         In[v]++;
       }
       seen.assign(pairs.size(),false);

       int start=-1; 
       for(int i=0;i<pairs.size();i++){
         int u=pairs[i][0],v=pairs[i][1];
         int o=-1,in=-1;
         if(Out.find(u)!=Out.end()){
            o=Out[u];
         }
         if(In.find(u)!=Out.end()){
            in=In[u];
         }
         if((o-in)==1){
            // cout << "here1 " << u << " in " << In[u] << " " << Out[u] << endl;
             start=u;
             break;
         } 

         o=-1,in=-1;
          if(Out.find(v)!=Out.end()){
            o=Out[v];
         }
         if(In.find(v)!=Out.end()){
            in=In[v];
         } 
         
         if((o-in)==1){
            start=v;
            //   cout << "here2 " << v << " in " << In[v] << " " << Out[v] << endl;
            break;
         }
       }
         if(start==-1) start=pairs[0][0];
         dfs(start);
        //  cout << "start " << start << endl;

        int n=pairs.size();
        // reverse(path.begin(),path.end());
        vector<vector<int>>ans(n,vector<int>(2));
        int k=0;
        for(int i=path.size()-1;i>=1;i--){
           int u=path[i],v=path[i-1];
           ans[k][0]=u;
           ans[k][1]=v;
           k++;
        }
      return ans;
    }
};