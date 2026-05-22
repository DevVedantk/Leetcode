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
    int evenSumSubgraphs(vector<int>& arr, vector<vector<int>>& edges) {
          int n=arr.size();
          int cnt=0;
          for(int i=0;i<(1<<n);i++){
              set<int>st;
              int sum=0;
              for(int j=0;j<n;j++){
                if(i&(1<<j)){
                     st.insert(j);  
                     sum+=arr[j];
                } 
              }
               int comp=st.size();
              vector<int>par(n);
              vector<int>rank(n);
               for(int j=0;j<par.size();j++) par[j]=j;

              for(int j=0;j<edges.size();j++){
                int u=edges[j][0],v=edges[j][1];
                if(st.find(u)!=st.end() && st.find(v)!=st.end()){
                    if(find(u,par)!=find(v,par)){
                        unions(u,v,par,rank);
                        comp--;
                    }
                }
              }

              if(comp==1 && sum%2==0) cnt++;
          }

   return cnt;
    }
};