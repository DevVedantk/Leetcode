class Solution {
public:
    int smallestNumber(int n) {
        if(n==1) return 1;
        vector<int>twos(12);
        twos[0]=1;

        for(int i=1;i<twos.size();i++){
            twos[i]=2*twos[i-1];
        }

         for(int i=0;i<twos.size();i++){
            if(n<twos[i]) return (twos[i]-1);
         }   
       
        return 0;
    }
};