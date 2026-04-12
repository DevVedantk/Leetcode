class Solution {
public:
    int MOD = 1e9+7;

    long long power(long long a, long long b){
        if(b==0) return 1;
        long long h = power(a, b/2);
        if(b%2==0) return (h%MOD*h%MOD)%MOD;
        return (h%MOD*h%MOD*a%MOD)%MOD;
    }

    int maxValue(vector<int>& ones, vector<int>& zero) {
        int n = ones.size();

        vector<pair<int,int>> v;
        long long extraOnes = 0;

        for(int i=0;i<n;i++){
            if(zero[i] == 0){
                extraOnes += ones[i];
            } else {
                v.push_back({ones[i], zero[i]});
            }
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a.first==b.first) return a.second<b.second;
           return a.first>b.first;
        });

        long long ans = 0;
        long long p_cnt = 0;

     
        for(int i=v.size()-1; i >= 0; i--){
            p_cnt += v[i].second;

            long long t1 = power(2, p_cnt) % MOD;
            long long t2 = (power(2, v[i].first) - 1 + MOD) % MOD;

            ans = (ans + t1 * t2) % MOD;

            p_cnt += v[i].first;
        }

        if(extraOnes > 0){
            long long t1 = power(2, p_cnt) % MOD;
            long long t2 = (power(2, extraOnes) - 1 + MOD) % MOD;

            ans = (ans + t1 * t2) % MOD;
        }

        return ans;
    }
};