class Solution {
public:

  vector<vector<int>>adj;
    vector<vector<int>>rev;
    vector<bool>vis;
    
stack<int>order;
void dfs_normal(int node){
    vis[node]=true;
    
    for(int child:adj[node]){
        if(vis[child]==false){
            dfs_normal(child);
        }
    }
    order.push(node);
}
 
void dfs_rev(int node,vector<int>&comp){
    vis[node]=true;
    comp.push_back(node);
        for(int child:rev[node]){
        if(vis[child]==false){
            dfs_rev(child,comp);
        }
}
}

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
         vis.assign(n+1,false);
    adj.resize(n);
    rev.resize(n);

     for(int a=0;a<n;a++){
         int b=edges[a];
         if(b==-1) continue;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

      for(int i=0;i<n;i++){
        if(vis[i]==false){
            dfs_normal(i);
        }
    }
    
    vis.assign(n,false);
    vector<int>king(n,0);
    int cur=1;
    while(order.size()>0){
        int node=order.top();
        order.pop();
        
        if(vis[node]==false){
            vector<int>comp;
            dfs_rev(node,comp);
            
            for(int ele:comp){
                king[ele]=cur;
            }
            cur++;
        }
    }

    map<int,int>mp;
    for(int i=0;i<king.size();i++) mp[king[i]]++;

    int size=0;
    for(auto ele:mp){
        size=max(size,ele.second);
    }

    return size==1 ? -1 :size;



    }
};