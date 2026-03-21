class Solution {
public:
        map<string,vector<pair<string,double>>>adj;
        map<string,bool>vis;
   double q_ans;
   bool dfs(string st,string en,double product){
         
         if(adj.find(st)==adj.end() || adj.find(en)==adj.end()){
            return false;
         }
        
        if(st==en){
            q_ans=product;
            return true;
        }
        
        bool temp=false;
        vis[st]=true;

        for(int i=0;i<adj[st].size();i++){
            if(vis[adj[st][i].first]==false){
                vis[adj[st][i].first]=true;
               temp=dfs(adj[st][i].first,en,product*adj[st][i].second);
               if(temp) break;
            }
        }
      return temp;

   }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& queries) { 
             
             for(int i=0;i<eq.size();i++){
                 adj[eq[i][0]].push_back({eq[i][1],val[i]});
                 adj[eq[i][1]].push_back({eq[i][0],1/val[i]});
             }

     vector<double>ans;

             for(int i=0;i<queries.size();i++){
                string st=queries[i][0],en=queries[i][1];
               q_ans=1;
               vis.clear();
                bool findPath=dfs(st,en,1);
                if(findPath) ans.push_back(q_ans);
                else ans.push_back(-1.0);
             }
//   ans.push_back(-1.0);

  return ans;
    }
};