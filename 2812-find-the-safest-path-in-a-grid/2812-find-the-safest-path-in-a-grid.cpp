class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>>dist(n,vector<int>(n));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    dist[i][j]=0;
                    q.push({i,j});
                }
                else dist[i][j]=-1;
            }
        }
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size()>0){

             int size=q.size();

             for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int newx=dir[d].first+x;
                    int newy=dir[d].second+y;
                    if(newx>=0 && newy>=0 && newx<n && newy<n && dist[newx][newy]==-1){
                        dist[newx][newy]=dist[x][y]+1;
                        q.push({newx,newy});
                    }
                }
             }    

        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout << dist[i][j] << " ";
        //     cout << endl;
        // }

        int ans=INT_MAX;

        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dist[0][0],{0,0}});
        
        bool found=false;
        set<pair<int,int>>vis;
        while(pq.size()>0 && !found){
              auto p=pq.top();
              pq.pop();

              int dis=p.first;
              auto [x,y]=p.second;
            //   cout << "dist " << dis  << endl;
              auto curr=make_pair(x,y);
              
              if(vis.find(curr)!=vis.end()) continue;
              vis.insert(curr);

              ans=min(ans,dis);
              if(x==n-1 && y==n-1) found=true;

              for(int d=0;d<4;d++){
                 int newx=dir[d].first+x;
                    int newy=dir[d].second+y;
                  if(newx>=0 && newy>=0 && newx<n && newy<n && vis.find(make_pair(newx,newy))==vis.end()){
                    // cout << "putting " << dist[newx][newy] << endl;
                    pq.push({dist[newx][newy],{newx,newy}});
                  }
              }

        }

        return ans;

    }
};