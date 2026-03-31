class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& sup) {
        
        map<string,vector<string>>adj;
        set<string>st;
        set<string>rec;
        for(string ele:sup) st.insert(ele);
        for(string ele:recipes) rec.insert(ele);
    
         
         map<string,int>deg;
         

         int n=recipes.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                 deg[ingredients[i][j]]=0;
                  deg[recipes[i]]=0;
            }
        }

          for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                // adj[ingredients[i][j]].push_back(recipes[i]);
                //  mp[ingredients[i][j]]=0;
                  deg[recipes[i]]++;
            }
        }

        

        queue<string>q;
        for(auto ele:deg){
            if(ele.second==0 && st.find(ele.first)!=st.end()){
                q.push(ele.first);
            }
        }

        cout << q.size() << endl;

        vector<string>ans;

        while(q.size()>0){
            string node=q.front();
            q.pop();
              if(rec.find(node)!=rec.end()) ans.push_back(node);
            
            for(string ele:adj[node]){
                deg[ele]--;
                if(deg[ele]==0){
                    q.push(ele);
                }
            }
        }

        return ans;


    }
};