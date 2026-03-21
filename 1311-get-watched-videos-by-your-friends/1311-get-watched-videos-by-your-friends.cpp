class Solution {
public:
map<string,int>mp;
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
            int lvl=0;
            int n=watchedVideos.size();
          

            vector<vector<int>>adj(n);

            for(int i=0;i<friends.size();i++){
                int a=i;
                for(int j=0;j<friends[i].size();j++){
                    int b=friends[i][j];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }

              queue<pair<int,int>>q;
            q.push({id,0});
            vector<bool>vis(n,false);
            vis[id]=true;
              
            while(q.size()>0){
               auto [node,lvl]=q.front();
               q.pop();
              
             
             for(int child:adj[node]){
                if(vis[child]==false){
                    vis[child]=true;
                    if(lvl+1==level){
                        for(int i=0;i<watchedVideos[child].size();i++){
                            string s=watchedVideos[child][i];
                            mp[s]++;
                        }
                    }
                    q.push({child,lvl+1});
                }
             }
            }

         vector<pair<int,string>>arr;

         for(auto ele:mp){
            arr.push_back({ele.second,ele.first});
         }

         sort(arr.begin(),arr.end());

        vector<string> ans;
        for(auto p:arr) ans.push_back(p.second);
            return ans;


    }
};