class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long ans=1e15;
        ans=min(ans,(long long)cost1*need1+(long long)cost2*need2);

        if(need1<=need2){
            ans=min(ans,(long long)need1*costBoth+(long long)(need2-need1)*cost2);
        } else if(need2<need1){
             ans=min(ans,(long long)need2*costBoth+(long long)(need1-need2)*cost1);
        }
        ans=min(ans,(long long)max(need1,need2)*costBoth);
        return ans;
    }
};