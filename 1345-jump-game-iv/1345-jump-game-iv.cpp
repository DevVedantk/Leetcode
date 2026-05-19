class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;


        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

         queue<tuple<int,int,int>>q;

         // index,element,steps
         int ans=INT_MAX;
         q.push({0,0,0});
         bool vis[n];
         for(int i=0;i<n;i++) vis[i]=false;

         while(q.size()>0){
            auto [idx,ele,steps]=q.front();
            q.pop();
            if(vis[idx]) continue;
                            if(idx==n-1){
                                 ans=min(ans,steps);
                              
                            }
             
             vis[idx]=true;
              
             if(idx-1>=0 && !vis[idx-1]) q.push({idx-1,arr[idx-1],steps+1}); 
             if(idx+1<n && !vis[idx+1]) q.push({idx+1,arr[idx+1],steps+1});

             vector<int>v=mp[arr[idx]];

             for(int child_idx:v){
                if(vis[child_idx]) continue;
                q.push({child_idx,arr[child_idx],steps+1});
             } 
             mp[arr[idx]].clear();

         }
      

         return ans;
    }
};