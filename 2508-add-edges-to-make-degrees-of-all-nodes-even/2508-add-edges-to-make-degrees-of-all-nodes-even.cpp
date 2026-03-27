class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int>deg(n+1,0);
      vector<unordered_set<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            deg[u]++;
            deg[v]++;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        vector<int>odd;
        for(int i=1;i<=n;i++){
            if(deg[i]%2!=0) odd.push_back(i);
        }
        
        if(odd.size()==0) return true;
        if(odd.size()==2) {
             int a=odd[0], b=odd[1];

             if(!adj[a].count(b)) return true;

                for(int i = 1; i <= n; i++){
                if(i != a && i != b && !adj[a].count(i) && !adj[b].count(i)){
                    return true;
                }
            }
        }

        if(odd.size()==4){
            int a=odd[0],b=odd[1],c=odd[2],d=odd[3];
        
             if(!adj[a].count(b) && !adj[c].count(d)) return true;    
             if(!adj[a].count(c) && !adj[b].count(d)) return true;
             if(!adj[a].count(d) && !adj[b].count(c) ) return true;

        }

        return false;


         
         

    }
};