class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int x1=0,x2=0;
        int ans=INT_MIN;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L' || moves[i]=='_') x1--;
            if(moves[i]=='R') x1++;

            if(moves[i]=='L') x2--;
            if(moves[i]=='R' || moves[i]=='_') x2++;
        }
        ans=max({ans,abs(x1),abs(x2)});
       
        return ans;
    }
};