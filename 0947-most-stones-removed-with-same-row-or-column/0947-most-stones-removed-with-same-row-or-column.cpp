class Solution {
public:
int find(int x,vector<int>&par){
    if(x==par[x]) return x;
    return par[x]=find(par[x],par);
}

void unions(int x,int y,vector<int>&rank,vector<int>&par){
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

    int removeStones(vector<vector<int>>& st) {
          int n=st.size();
          
          vector<int>par(n,0);
          vector<int>rank(n,0);

          for(int i=0;i<n;i++) par[i]=i;
          for(int i=0;i<st.size();i++){
            for(int j=i+1;j<st.size();j++){
                if(st[i][0]==st[j][0] || st[i][1]==st[j][1]){
                   if(find(i,par)!=find(j,par)) unions(i,j,rank,par);
                }
            }
          }

          int g=0;
          for(int i=0;i<n;i++){
            if(find(i,par)==i) g++;
          }

          return n-g;

    }
};