class Solution {
public:
int find(int x,vector<int>&par){
    if(x==par[x]) return x;
    return par[x]=find(par[x],par);
}
void unions(int x,int y,vector<int>&par,vector<int>&rank){
    int x_par=find(x,par);
    int y_par=find(y,par);

    if(x_par==y_par) return ;

   if(rank[x_par]<rank[y_par]){
       par[x_par]=y_par;
   }  else if(rank[x_par]>rank[y_par]){
       par[y_par]=x_par;
   } else{
    par[x_par]=y_par;
    rank[y_par]++;
   }

}

bool check(int x,int y, vector<vector<int>>& res,vector<int>&par){
    for(int i=0;i<res.size();i++){
        int xp=find(x,par);
        int yp=find(y,par);
        int ap=find(res[i][0],par);
        int bp=find(res[i][1],par);

        if(xp==ap && yp==bp) return false;
        if(xp==bp && yp==ap) return false;
    }
    return true;
}

vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        vector<int>par(n,0);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++) par[i]=i;

        vector<bool>ans(req.size());

        for(int i=0;i<req.size();i++){
            int x=req[i][0],y=req[i][1];
            if(check(x,y,res,par)){
                unions(x,y,par,rank);
                ans[i]=true;
            } else ans[i]=false;
        }

        return ans;
    }
};