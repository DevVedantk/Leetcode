class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int fp) {
        map<int,vector<pair<int,int>>>mp;

        for(int i=0;i<meet.size();i++){
            int p1=meet[i][0];
            int p2=meet[i][1];
            int time=meet[i][2];
            mp[time].push_back({p1,p2});
        }
      
        vector<bool>knows(n,false);
        knows[0]=true;knows[fp]=true;

        for(auto p:mp){
            int time=p.first;
            vector<pair<int,int>>pers=p.second;

            unordered_set<int>already;
            unordered_map<int,vector<int>>adj;
            queue<int>q;

            for(auto [p1,p2]:pers){
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);

                if(already.find(p1)==already.end() && knows[p1]){
                    q.push(p1);
                    already.insert(p1);
                }

                
                if(already.find(p2)==already.end() && knows[p2]){
                    q.push(p2);
                    already.insert(p2);
                }
            }


            while(q.size()>0){
                int t=q.front();
                q.pop();

                for(int child:adj[t]){
                    if(knows[child]==false){
                knows[child]=true;
                        q.push(child);
                    }
                }
            }

        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(knows[i]) ans.push_back(i);
        }

        return ans;
    }
};