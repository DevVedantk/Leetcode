class Solution {
public:
    bool judgeCircle(string moves) {
        
        int r=0,c=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') r--;
            if(moves[i]=='D') r++;
            if(moves[i]=='R') c++;
            if(moves[i]=='L') c--;
        }

        return (r==0 && c==0);
    }
};