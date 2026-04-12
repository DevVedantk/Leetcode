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

long long countPairs(int n, vector<vector<int>>& edges) {
           vector<int>rank(n,0);
           vector<int>par(n,0);
           

           for(int i=0;i<n;i++) par[i]=i;

          for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            if(find(u,par)!=find(v,par)) unions(u,v,rank,par);
          }


          map<int,int>mp;
          for(int i=0;i<par.size();i++) mp[find(i,par)]++;
        //   for(auto e:mp) cout << e.first << " " << e.second << endl; 
    
    vector<int>comp;
   for(auto ele:mp) comp.push_back(ele.second);
   long long sum=0;
   long long ans=0;

   cout << mp.size() <<  endl;

   for(int i=comp.size()-1;i>=1;i--){
        sum=sum+comp[i];
        ans=ans+comp[i-1]*sum;
   }

      return ans;

    }
};