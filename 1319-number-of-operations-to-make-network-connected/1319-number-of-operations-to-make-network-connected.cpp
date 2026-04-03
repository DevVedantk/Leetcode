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

    if(rank[x_par] < rank[y_par]){
        par[x_par]=y_par;
    } else if(rank[x_par]>rank[y_par]){
        par[y_par]=x_par;
    } else{
        par[x_par]=y_par;
        rank[y_par]++;
    }
}

    int makeConnected(int n, vector<vector<int>>& edges) {
         
         vector<int>par(n,0);
         vector<int>rank(n,0);
         for(int i=0;i<n;i++) par[i]=i;
         
         int cy=0;
         int component=0;

         for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];

            if(find(a,par)==find(b,par)) cy++;
            else{
                unions(a,b,par,rank);
            }
         }

         for(int i=0;i<n;i++){
            if(find(i,par)==i) component++;
         }
         if(component-1<=cy) return component-1;  
         else return -1;


    }
};