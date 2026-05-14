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

    if(rank[x_par]<rank[y_par]){
        par[x_par]=y_par;
    } else if(rank[x_par]>rank[y_par]){
        par[y_par]=x_par;
    } else{
        par[x_par]=y_par;
        rank[y_par]++;
    }
}

pair<int,int> find_mst( vector<vector<int>>& edges,int idx,int n,int force){
       vector<int>par(n,0);
             vector<int>rank(n,0);
      for(int i=0;i<n;i++) par[i]=i;
      int t=0;
      if(force!=-1){
         int a = edges[force][0];
         int b = edges[force][1];
         int wt = edges[force][2];
         t += wt;
         unions(a,b,par,rank);
      }

      for(int i=0;i<edges.size();i++){
        int a=edges[i][0],b=edges[i][1],wt=edges[i][2];
        if(idx==i) continue;
        if(find(a,par)!=find(b,par)){
            t+=wt;
            unions(a,b,par,rank);
        }
      }
      int c=0;
      for(int i=0;i<n;i++){
        if(find(i,par)==i) c++;
      }

      return {t,c} ;

}
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
               for(int i=0;i<edges.size();i++){
                   edges[i].push_back(i);
               }
            
             sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
                return a[2]<b[2];
             });

       vector<vector<int>>ans(2);
       int mst=find_mst(edges,-1,n,-1).first;
       
        for(int i=0;i<edges.size();i++){
              auto [cost,comp]=find_mst(edges,i,n,-1);
              if(cost>mst || comp>1) ans[0].push_back(edges[i][3]);
              else {
                auto [cost2,comp2]=find_mst(edges,-1,n,i);
                if(cost2==mst) ans[1].push_back(edges[i][3]);
              }
        }
   
   return ans;

    }
};