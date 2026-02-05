class Solution {
public:
static const int MXN = 3001;
    static const long long INF = 1e17;

    long long psum[MXN];
    long long dp[MXN][MXN];
void dnc(int i, long long l, long long r, long long optl,long long optr) {
    if (l > r) return;
 
    long long mid = (l + r) / 2;
 
    pair<long long, long long> best = {INF, l};
 
    for (long long j = optl; j < min(mid, optr + 1); j++) {
        long long sum = psum[mid] - psum[j];
        best = min(best, make_pair((sum * (sum+1)/2) + dp[i - 1][j], j));
    }
 
    dp[i][mid] = best.first;
 
    long long opt = best.second;
    dnc(i, l, mid - 1, optl, opt);
    dnc(i, mid + 1, r, opt, optr);
}

    long long minPartitionScore(vector<int>& arr, int k) {

        int N=arr.size();
        // psum[]
        // psum[1]=arr[0];
        
        for(int i=1;i<=N;i++){
            psum[i]=psum[i-1]+arr[i-1];
        }
 
      for (int j = 0; j <= N; j++)
        dp[0][j] = INF;
 
       dp[0][0] = 0;
 
      for (int i = 1; i <= k; i++)
        dnc(i, 1, N, 0, N - 1);

        return dp[k][N];
    }
};