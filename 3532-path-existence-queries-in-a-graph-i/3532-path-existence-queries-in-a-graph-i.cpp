class Solution {
public:
int find(int x,vector<int>&par){
    if(x==par[x]) return x;

   return par[x]=find(par[x],par);
}

void unions(int x,int y,vector<int>&par,vector<int>&rank){
    int x_par=find(x,par);
    int y_par=find(y,par);

    if(x_par==y_par) return;

    if(rank[x_par]>rank[y_par]){
        par[y_par]=x_par;
    } else if(rank[y_par]>rank[x_par]){
        par[x_par]=y_par;
    } else{
        par[y_par]=x_par;
        rank[x_par]++;
    }
}
    vector<bool> pathExistenceQueries(int n, vector<int>& arr, int maxd, vector<vector<int>>& q) {
            vector<int>par(n),rank(n,0);
            for(int i=0;i<n;i++) par[i]=i;
          
          for(int i=0;i<arr.size()-1;i++){
               int u=arr[i];
               int v=arr[i+1];
               if(abs(v-u)<=maxd){
                // cout << u << " " << v << " " << "here" << endl;
                if(find(i,par)!=find(i+1,par)) unions(i,i+1,par,rank);
               }
          }

          vector<bool>ans(q.size());

          for(int i=0;i<q.size();i++){
            int u=q[i][0],v=q[i][1];

           if(find(v,par)==find(u,par)) ans[i]=true;
           else ans[i]=false;
          }

          return ans;
             
    }
};