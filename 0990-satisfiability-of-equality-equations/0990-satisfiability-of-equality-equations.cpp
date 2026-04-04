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

bool equationsPossible(vector<string>& eq) {

    vector<int>rank(26,0);
    vector<int>par(26,0);
    for(int i=0;i<26;i++) par[i]=i;
          
          for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='!') continue;

            int a=eq[i][0]-'a';
            int b=eq[i][3]-'a';
            if(find(a,par)!=find(b,par)) unions(a,b,par,rank);
          }

          for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='=') continue;

           int a=eq[i][0]-'a';
            int b=eq[i][3]-'a';
            if(find(a,par)==find(b,par)) return false;
          }
         
         return true;


    }
};