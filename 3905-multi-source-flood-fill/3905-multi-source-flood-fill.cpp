class Solution {
public:

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& src) {

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<tuple<int,int,int,int>> q;

   
        for(auto &it : src){

            int x = it[0];
            int y = it[1];
            int color = it[2];

            ans[x][y] = color;
            dist[x][y] = 0;

            q.push({x,y,color,0});
        }

        vector<pair<int,int>> dir = {
            {1,0},{0,1},{-1,0},{0,-1}
        };

        while(!q.empty()){

            int size = q.size();

            // same BFS level = same time
            for(int i=0;i<size;i++){

                auto [x,y,color,d] = q.front();
                q.pop();

                for(auto &it : dir){

                    int nx = x + it.first;
                    int ny = y + it.second;

                    if(nx>=0 && ny>=0 && nx<n && ny<m){

                        int nd = d + 1;

                        // shorter distance
                        if(nd < dist[nx][ny]){

                            dist[nx][ny] = nd;
                            ans[nx][ny] = color;

                            q.push({nx,ny,color,nd});
                        }

                        // same distance -> bigger color wins
                        else if(nd == dist[nx][ny] &&
                                color > ans[nx][ny]){

                            ans[nx][ny] = color;

                            q.push({nx,ny,color,nd});
                        }
                    }
                }
            }
        }

        return ans;
    }
};