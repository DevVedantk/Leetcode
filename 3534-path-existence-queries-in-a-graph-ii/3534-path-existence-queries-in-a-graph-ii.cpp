class Solution {
public:

int getFarthest(vector<pair<int,int>>&arr,int target){
    int n=arr.size();
    int lo=0,hi=n-1;
    int res=0;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(arr[mid].first<=target){
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }

    return res;
}
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxd, vector<vector<int>>& q) {
           vector<pair<int,int>>arr(n);

           for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
           }

           sort(arr.begin(),arr.end());
           
           vector<int>indexToNode(n);

           for(int i=0;i<n;i++){
            int node=arr[i].second;
            indexToNode[node]=i;
           }
           
           int row=n;
           int col=log2(n)+1;

           vector<vector<int>>binary(row,vector<int>(col));

           for(int node=0;node<n;node++){
               int farthestInOneHope=getFarthest(arr,arr[node].first+maxd);
               binary[node][0]=farthestInOneHope;
           }

vector<int>ans;
           for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                binary[node][j]=binary[binary[node][j-1]][j-1];
            }
           }

           for(int i=0;i<q.size();i++){
            int u=q[i][0];
            int v=q[i][1];

            int a=indexToNode[u];
            int b=indexToNode[v];
            
            if(a==b) {
                ans.push_back(0);
                continue;
            }

            if(a>b) swap(a,b);
            
            int jump=0;
            int curr=a;
            for(int j=col-1;j>=0;j--){
                if(binary[curr][j]<b){
                    curr=binary[curr][j];
                    jump+=(1<<j);
                }
            }

            if(binary[curr][0]>=b){
                ans.push_back(jump+1);
            } else ans.push_back(-1);

           
           }

           return ans;

    }
};