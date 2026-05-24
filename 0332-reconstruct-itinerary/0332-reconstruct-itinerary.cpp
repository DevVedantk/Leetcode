class Solution {
public:
    map<string,vector<pair<string,int>>>adj;
    vector<bool>seen;
    vector<string>path;


    void dfs(string node){
        while(adj[node].size()>0){
            auto edge=adj[node].back();
            adj[node].pop_back();

            if(seen[edge.second]) continue;
            seen[edge.second]=true;
            dfs(edge.first);
        }
        path.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tick) {
           
           for(int i=0;i<tick.size();i++){
            adj[tick[i][0]].push_back({tick[i][1],i});
           }

            // int n=tick.
           seen.assign(tick.size(),false);
           for(auto& ele:adj){
            vector<pair<string,int>>&arr=ele.second;
            sort(arr.begin(),arr.end());
            reverse(arr.begin(),arr.end());
            ele.second=arr;
           }

        //    for(auto ele:adj){
        //     cout << ele.first << " -> ";
        //     for(auto e:ele.second) cout << e.first << " " <<e.second << " ";
        //     cout << endl;
        //    }

           dfs("JFK");
           reverse(path.begin(),path.end());

           return path;

        //    return {};
    }
};