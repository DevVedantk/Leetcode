class Solution {
public:
vector<bool>vis;
vector<bool>vis1;

bool check(int node,vector<vector<int>>&adj){

    queue<int>q2;
    q2.push(node);
    int cnt=0;
    vis1[node]=true;
    while(q2.size()>0){
         int top=q2.front();
         q2.pop();
          cnt++;

        for(int child:adj[top]){
            if(vis1[child]==false){
                vis1[child]=true;
                q2.push(child);
               
            }
        }
    }
    // cout << "size " << cnt << endl;
    bool flag=true;

    queue<int>q;

    q.push(node);
    vis[node]=true;
    while(q.size()>0){
        int node=q.front();
        q.pop();

        if((cnt-1)!=adj[node].size()) flag=false;

        for(int child:adj[node]){
            if(vis[child]==false){
                
            vis[child]=true;
            q.push(child);
            }
        }
    }

    return flag;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vis.assign(n,false);
        vis1.assign(n,false);

        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                 if(check(i,adj)){
                    cnt++;
                 }
            }
        }

        return cnt;
    }
};