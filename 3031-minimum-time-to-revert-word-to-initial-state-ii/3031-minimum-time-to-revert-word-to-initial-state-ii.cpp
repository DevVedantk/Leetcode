class Solution {
public:
vector<int> kmp(string& s){
    vector<int>lps(s.size());

    int pref=0,suff=1;
    while(suff<s.size()){
        if(s[pref]==s[suff]){
            lps[suff]=pref+1;
            pref++;suff++;
        } else{
            if(pref==0){
                lps[suff]=0;
                suff++;
            } else pref=lps[pref-1];
        }
    }

    return lps;
}
int minimumTimeToInitialState(string word, int k) {
       int n=word.size();
       vector<int>lps=kmp(word);

       int lpslen=lps[lps.size()-1];
        int j=lpslen-1;
       while(j>0 && (n-lpslen)%k!=0){
        lpslen=lps[j];
        j=lpslen-1;
       }
       
       return (n-lpslen+k-1)/k;
    }
};