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

int maxActivated(vector<vector<int>>& points) {
        map<int,vector<int>>mp1;
         
           
         int n=points.size();
         vector<int>par(n);
         vector<int>rank(n);


         for(int i=0;i<n;i++) par[i]=i;


         for(int i=0;i<points.size();i++){
            mp1[points[i][0]].push_back(i);
         }

            for(auto ele:mp1){
            if(ele.second.size()==1) continue;
            for(int j=1;j<ele.second.size();j++){
                 if(find(ele.second[j-1],par)!=find(ele.second[j],par)){
                    unions(ele.second[j-1],ele.second[j],par,rank);
                 }
            }
         }

         mp1.clear();
            
         
         for(int i=0;i<points.size();i++){
            mp1[points[i][1]].push_back(i);
         }

           for(auto ele:mp1){
            if(ele.second.size()==1) continue;
            for(int j=1;j<ele.second.size();j++){
                 if(find(ele.second[j-1],par)!=find(ele.second[j],par)){
                    unions(ele.second[j-1],ele.second[j],par,rank);
                 }
            }
         }
        
        //  for(auto e:mp1){
        //     cout << e.first << " ";
        //     for(int ele:e.second) cout << ele << " ";
        //     cout << endl;
        //  }

      
         map<int,int>mp;

         for(int i=0;i<n;i++){
            mp[find(i,par)]++;
         }
          
          int fmax=INT_MIN,smax=INT_MIN;

          
         for(auto ele:mp){
            if(ele.second>=fmax){
                smax=fmax;
                fmax=ele.second;
            } else if(ele.second>=smax) smax=ele.second;
         }
         
        //  for(auto ele:mp) cout << ele.first << " " << ele.second << endl;

        int ans=1+fmax;
        if(smax!=INT_MIN) ans+=smax;
     return ans;



    }
};