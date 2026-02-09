class Solution {
public:
int up[100001][20];
int lvl[100001];

void find_lvl(int node,int parent,vector<vector<int>>& adj,int level){
    lvl[node]=level;

    for(int child:adj[node]){
        if(child==parent) continue;
        find_lvl(child,node,adj,level+1);
    }
}

void binary_lifting(int node,int parent,vector<vector<int>>& adj){
     up[node][0]=parent;

     for(int i=1;i<20;i++){
        if(up[node][i-1]!=-1){
            up[node][i]=up[up[node][i-1]][i-1];
        } else up[node][i]=-1;
     }

     for(int child:adj[node]){
        if(parent==child) continue;
        binary_lifting(child,node,adj);
     }
}

int get_node(int node,int jump_req){
     
     if(node==-1 || jump_req==0) return node;
     
     for(int i=19;i>=0;i--){
        if(jump_req>=(1<<i)){
            return get_node(up[node][i],jump_req-(1<<i));
        }
     }
     return -1;

}

long long lca(int u,int v){
    if(lvl[u]<lvl[v]) swap(u,v);
    long long dis=0;
    
    dis=lvl[u]-lvl[v];
    u=get_node(u,lvl[u]-lvl[v]);

    if(v==u) return dis;
    
    long long jump=0;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            jump+=pow(2,i);
            u=up[u][i];
            v=up[v][i];
        }
    }
    jump*=2;

    return 2+jump+dis;
}

int MOD=1e9+7;
long long modexp(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
          int n=edges.size()+1;
         vector<vector<int>>adj(n+1);
         
         for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
         }
         find_lvl(1,-1,adj,0);
         binary_lifting(1,-1,adj);
         int q=queries.size();
         vector<int>path_len(q);

         for(int i=0;i<q;i++){
            int len=lca(queries[i][0],queries[i][1]);
            cout << "len is " << len << endl;
            path_len[i]=len;
         }

         
         vector<int>ans(q);
      
       for(int i=0;i<path_len.size();i++){
       if(path_len[i]==0) ans[i]=0;
       else ans[i]=modexp(2,path_len[i]-1);
       }
   return ans;
      
    }
};