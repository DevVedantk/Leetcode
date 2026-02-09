class Solution {
public:
int lvl[10001];
int up[10001][20];

vector<vector<int>> freq;

void find_level(int node,int parent,map<int,vector<pair<int,int>>>& adj,int level){
    lvl[node]=level;

    for(auto& [child,wt]:adj[node]){
        if(child==parent) continue;
        find_level(child,node,adj,level+1);
    }
}

void binary_lifting(int node,int parent,map<int,vector<pair<int,int>>>& adj){
     up[node][0]=parent;

     for(int i=1;i<20;i++){
        if(up[node][i-1]!=-1){
            up[node][i]=up[up[node][i-1]][i-1];
        } else up[node][i]=-1;
     }

     for(auto& [child,wt]:adj[node]){
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
pair<int,int> lca(int u,int v){
    if(lvl[u]<lvl[v]) swap(u,v);
    int dis=lvl[u]-lvl[v];
    u=get_node(u,lvl[u]-lvl[v]);

      
      if(u==v) return {u,dis};
     int jump=0;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            jump+=pow(2,i);
            u=up[u][i];
            v=up[v][i];
        }
    }
    int lca_node=get_node(u,1);
    jump*=2;
    dis=dis+2+jump;
    return {lca_node,dis};
}

void find_freq(int node,int parent,map<int,vector<pair<int,int>>>& adj){

    for(auto& [child,wt]:adj[node]){
        if(child==parent) continue;
       freq[child]=freq[node];
       freq[child][wt]++;
       find_freq(child,node,adj);
    }
}


    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& que) {
      map<int,vector<pair<int,int>>>adj;

      for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
      }
    freq.assign(n,vector<int>(30));
      find_level(0,-1,adj,0);
      binary_lifting(0,-1,adj);
      find_freq(0,-1,adj);

    
    int q=que.size();
    vector<int>ans(q);
   
   for(int i=0;i<q;i++){
    int u=que[i][0],v=que[i][1];
     pair<int,int> pair_ans=lca(u,v);
     int len=pair_ans.second;
     int lca_node=pair_ans.first;
      
      int maxfreq=0;
     for(int j=1;j<=26;j++){
      int curr=freq[u][j]+freq[v][j]-(2*(freq[lca_node][j]));
      maxfreq=max(maxfreq,curr);
     }
     ans[i]=(len-maxfreq);
   }

    return ans;

        
    }
};