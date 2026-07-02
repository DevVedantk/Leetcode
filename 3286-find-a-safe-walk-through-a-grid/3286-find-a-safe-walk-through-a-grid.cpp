class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

              int m=grid.size();
              int n=grid[0].size();

              vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
              dist[0][0]=grid[0][0];

              set<pair<int,int>>vis;
              priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

              vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

              pq.push({dist[0][0],{0,0}});

              while(pq.size()>0){
                  auto p=pq.top();
                  pq.pop();
                 int curr_dis=p.first;
                  auto [x,y]=p.second;
                  
                  auto pair=make_pair(x,y);
                  if(vis.find(pair)!=vis.end()) continue;
                  vis.insert(pair);

                  for(int d=0;d<4;d++){
                    int newx=dir[d].first+x;
                    int newy=dir[d].second+y;

                    if(newx>=0 && newy>=0 && newx<m && newy<n && vis.find(make_pair(newx,newy))==vis.end()){
                         dist[newx][newy]=min(dist[newx][newy],curr_dis+grid[newx][newy]);
                         pq.push({dist[newx][newy],{newx,newy}});
                    }
                  }
              }

              return (health-dist[m-1][n-1])>=1; 

    }
};