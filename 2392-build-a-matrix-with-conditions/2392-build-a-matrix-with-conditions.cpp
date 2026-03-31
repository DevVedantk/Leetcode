class Solution {
public:
vector<int> topo(vector<vector<int>>&adj,int n){
    vector<int>deg(n+1,0);
    for(int i=0;i<adj.size();i++){
        for(int ele:adj[i]){
            deg[ele]++;
        }
    }

    vector<int>res;
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push(i);
    }

    while(q.size()>0){
        int node=q.front();
        q.pop();

        res.push_back(node);

        for(int child:adj[node]){
            deg[child]--;
            if(deg[child]==0) q.push(child);
        }
    }

    return res;
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>adj1(k+1);
        for(int i=0;i<rowConditions.size();i++){
            adj1[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }

         vector<vector<int>>adj2(k+1);
        for(int i=0;i<colConditions.size();i++){
            adj2[colConditions[i][0]].push_back(colConditions[i][1]);
        }


        vector<int>r1=topo(adj1,k);
        vector<int>r2=topo(adj2,k);
        
       
        if(r1.size()!=k || r2.size()!=k) return {};


        map<int,int>col;
        map<int,int>row;
    for(int i=0;i<k;i++){
        row[r1[i]]=i;
        col[r2[i]]=i;
    }

    vector<vector<int>> ans(k,vector<int>(k,0));
    for(auto ele:col){
        int idx1=ele.second;
       int idx2=row[ele.first];
       ans[idx2][idx1]=ele.first;
    }

    return ans;


    }
};