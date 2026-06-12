class Solution {
public:

vector<int>lvl;
int up[200001][20];


void dfs(int node,int parent,vector<vector<int>>& adj,int level){
     lvl[node]=level;
     
     for(int child:adj[node]){
         if(child==parent) continue;
         dfs(child,node,adj,level+1);
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
        if(child==parent) continue;
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

int dist(int u,int v){
    //lca of u and v
    int dis=0;
    
    if(lvl[u]<lvl[v]){
        swap(u,v);
    }
    
    dis=lvl[u]-lvl[v];
    u=get_node(u,lvl[u]-lvl[v]);
    
    if(u==v) return dis;
    
    int jump=0;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            jump+=pow(2,i);
            v=up[v][i];
        }
    }
    jump*=2;
    return dis+2+jump;
}

int dp[100001][2];
int MOD=1e9+7;
int solve(int len,int sum){
    if(len==0){
        return (sum!=0);
    }
    
    if(dp[len][sum]!=-1) return dp[len][sum];
    int ans=0;

   ans=(ans+solve(len-1,(sum+1)%2))%MOD;
   ans=(ans+solve(len-1,(sum+2)%2))%MOD;

   return dp[len][sum]=ans;
}

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& q) {
          int n=edges.size()+1;

          lvl.assign(n+1,0);

            vector<vector<int>>adj(n+1);

          for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
          }

          dfs(1,-1,adj,0);
          
          memset(dp,-1,sizeof(dp));

          binary_lifting(1,-1,adj);

          vector<int>ans;

          for(int i=0;i<q.size();i++){
            int u=q[i][0],v=q[i][1];

            int d=dist(u,v);
            // cout << "dist is " << "u " << u << " " << "v " << v << " " << d << endl;
            int path=solve(d,0);
           ans.push_back(path);
          }

        //   cout  <<"ops " << solve(1,0,0) << endl;

          return ans;

    }
};