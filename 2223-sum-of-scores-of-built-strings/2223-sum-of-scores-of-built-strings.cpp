class Solution {
public:
vector<int> zalgo(string& s){
    vector<int>z(s.size());
    int n=s.size();
    int l=0,r=0;
    for(int i=1;i<s.size();i++){
       if(i<r) z[i]=min(r-i,z[i-l]);

        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;

        if(i+z[i]>r){
            r=i+z[i];
            l=i;
        }
    }
    return z;
}
    long long sumScores(string s) {

      vector<int>z=zalgo(s);   
    long long ans=s.size();

    for(int i=0;i<z.size();i++) ans+=z[i];
    return ans;
    }
};