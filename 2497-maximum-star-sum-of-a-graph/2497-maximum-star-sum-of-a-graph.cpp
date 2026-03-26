class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
       int n=vals.size();
      vector<vector<int>>adj(n);
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0],v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);

       }
        
        int ans=INT_MIN;

       map<int,priority_queue<int>>mp;

       for(int i=0;i<n;i++){
         for(int child:adj[i]){
            mp[i].push(vals[child]);
         }
       }
     if(mp.size()==0){
        for(int ele:vals) ans=max(ans,ele);
        return ans;
     }
  

       for(int i=0;i<n;i++){
        int sum=vals[i];
        // cout << sum << "this " << endl;
      int cnt = k;
      priority_queue<int>pq=mp[i];
      while(cnt-- && pq.size()>0){
      if(pq.top()>0)  sum += pq.top();
        pq.pop();
        }
       ans = max(ans, sum);
       }

      return ans;
    }
};