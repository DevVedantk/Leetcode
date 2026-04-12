class Solution {
public:
int find(int x,vector<int>&par){
    if(x==par[x]) return x;
    return par[x]=find(par[x],par);
}

void unions(int x,int y,vector<int>&rank,vector<int>&par){
    int x_par=find(x,par);
    int y_par=find(y,par);

    if(x_par==y_par) return ;

    if(rank[x_par]<rank[y_par]){
        par[x_par]=y_par;
    } else if(rank[x_par]>rank[y_par]){
        par[y_par]=x_par;
    } else{
        par[x_par]=y_par;
        rank[y_par]++;
    }
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& que) {
          
          for(int i=0;i<que.size();i++) que[i].push_back(i);

          vector<int>par(n,0);
          vector<int>rank(n,0);
         sort(edge.begin(),edge.end(),[](const vector<int>&a,const vector<int>&b){
           return a[2]<b[2];
         }); 

         for(int i=0;i<n;i++) par[i]=i;
         
         
         sort(que.begin(),que.end(),[](const vector<int>&a,const vector<int>&b){
           return a[2]<b[2];
         });

              vector<bool>ans(que.size());
         int j=0;
         for(int i=0;i<que.size();i++){
              int d=que[i][2];
    
              while(j<edge.size() && edge[j][2]<d){
                unions(edge[j][0],edge[j][1],rank,par);
                j++;
              }
              if(find(que[i][0],par)==find(que[i][1],par)) ans[que[i][3]]=true;
              else ans[que[i][3]]=false;

         }

      return ans;

    }
};