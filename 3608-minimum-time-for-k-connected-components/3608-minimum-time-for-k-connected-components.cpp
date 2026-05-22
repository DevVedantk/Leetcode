class Solution {
public:
    stack<int>st;
    int find(int x,vector<int>&par){
        if(x==par[x]) return x;
        return par[x]=find(par[x],par);
    }

    void unions(int x,int y,vector<int>&par,vector<int>&rank){
       int x_par=find(x,par); 
       int y_par=find(y,par);
       if(x_par==y_par)  return;

       if(rank[x_par]>rank[y_par]){
         par[y_par]=x_par;
       } else if(rank[x_par]<rank[y_par]){
        par[x_par]=y_par;
       } else{
        par[x_par]=y_par;
        rank[y_par]++;
       }
    }
    int dsu(int n,vector<vector<int>>&edges,int times){

         int comp=n;
         vector<int>par(n,0); 
         vector<int>rank(n,0);
         for(int i=0;i<n;i++) par[i]=i;

         for(int i=0;i<edges.size();i++){
              if(edges[i][2]<=times) continue;
              int a=edges[i][0],b=edges[i][1];
              if(find(a,par)!=find(b,par)){
                unions(a,b,par,rank);
                comp--;
              }
         }

         return comp;

    } 
    int minTime(int n, vector<vector<int>>& edges, int k) {
         
          int lo=0,hi=1e9;
           int ans=INT_MAX;
          while(lo<=hi){
            int mid=(lo)+(hi-lo)/2;
             
             int comp=dsu(n,edges,mid);
             if(comp>=k){
                ans=mid;
                hi=mid-1;
             } else lo=mid+1;            
          }
          return ans;
    }
};