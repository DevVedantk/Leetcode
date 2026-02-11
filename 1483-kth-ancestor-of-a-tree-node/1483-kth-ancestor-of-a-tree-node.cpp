class TreeAncestor {
public:
vector<vector<int>>adj;
int up[50001][19];

void binary_lifting(int node,int parent,vector<vector<int>>& adj){
       
       up[node][0]=parent;
       for(int i=1;i<19;i++){
        if(up[node][i-1]!=-1){
                  up[node][i]=up[up[node][i-1]][i-1];
        } else up[node][i]=-1;
       }

       for(int child:adj[node]){
        if(child==parent) continue;
        binary_lifting(child,node,adj);
       }
}

int ans_query(int node,int jump_req){
    if(node==-1 || jump_req==0) return node;

    for(int i=19;i>=0;i--){
        if(jump_req>=(1<<i)){
            return ans_query(up[node][i],jump_req-(1<<i));
        }
    }
    return -1;

}

TreeAncestor(int n, vector<int>& parent) {
         adj.assign(n,vector<int>());
         for(int i=1;i<n;i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
         }
         binary_lifting(0,-1,adj);
    }
    
    int getKthAncestor(int node, int k) {
          return ans_query(node,k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */