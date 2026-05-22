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
        } else if(rank[x_par]<rank[y_par]){
            par[x_par]=y_par;
        } else{
            par[x_par]=y_par;
            rank[y_par]++;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
          
          int n=strs.size();
          vector<int>rank(n);   
          vector<int>par(n);

          for(int i=0;i<n;i++) par[i]=i;


          for(int i=0;i<n;i++){
              
            for(int j=i+1;j<n;j++){
                 int cnt=0;
                 for(int k=0;k<strs[j].size();k++){
                      if(strs[i][k]!=strs[j][k]) cnt++;
                 }
                 if(cnt<=2) unions(i,j,par,rank);   
            }
          }
         
         int grp=0;
          for(int i=0;i<n;i++){
            if(find(i,par)==i) grp++;
          }

          return grp;



    }
};