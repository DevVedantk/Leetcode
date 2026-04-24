class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int x=0;
        int ans=INT_MIN;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L' || moves[i]=='_') x--;
            if(moves[i]=='R') x++;
        }
        ans=max(ans,abs(x));
       
        x=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') x--;
            if(moves[i]=='R' || moves[i]=='_') x++;
        }
        ans=max(ans,abs(x));

        return ans;
    }
};