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
    if(rank[x_par] <rank[y_par]){
        par[x_par]=y_par;
    } else if(rank[x_par]>rank[y_par]){
        par[y_par]=x_par;
    } else{
        par[x_par]=y_par;
        rank[y_par]++;
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
           
           int n=isConnected.size();
           vector<int>par(n,0);
           vector<int>rank(n,0);

           for(int i=0;i<n;i++){
            par[i]=i;
           }

           for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
             if(isConnected[i][j]==1) unions(i,j,par,rank);
            }
           }
           
           int cnt=0;
           for(int i=0;i<n;i++){
            if(find(i,par)==i) cnt++;
           }
           return cnt;

    }
};