class Solution {
public:
vector<bool>vis;

void dfs(int node,vector<vector<int>>&room){
    
    vis[node]=true;
    for(int child:room[node]){
        if(vis[child]==false){
            dfs(child,room);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vis.assign(n,false);


       dfs(0,rooms); 

       for(int i=0;i<n;i++){
        if(vis[i]==false) return false;
       }
       return true;
    }
};