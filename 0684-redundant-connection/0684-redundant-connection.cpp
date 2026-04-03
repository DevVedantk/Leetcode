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

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n=edges.size();
           vector<int>par(n+1,0);
           vector<int>rank(n+1,0);
           for(int i=1;i<=n;i++) par[i]=i;
            
            vector<int>arr(2,0);
           for(int i=0;i<n;i++){
            int a=edges[i][0],b=edges[i][1];
            if(find(a,par)!=find(b,par)) unions(a,b,par,rank);
            else{
                arr[0]=a;
                arr[1]=b;
            }
           }

        return arr;

    }
};