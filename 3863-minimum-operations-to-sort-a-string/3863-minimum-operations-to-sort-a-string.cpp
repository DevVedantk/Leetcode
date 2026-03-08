class Solution {
public:
    string sorted(string s){
     sort(s.begin(),s.end());

        return s;
    }
    int minOperations(string s) {
        string dum=s;
     int n=s.size();

        if(sorted(dum)==s) return 0;
       string one=sorted(s);
       
        if(s.size()==2 && one!=s) return -1; 
       
              if((one[0]==s[0]) || (one[n-1]==s[n-1])) return 1;
        

        string ns="";
        string s1=s.substr(0,n-1);
        
         ns=sorted(s1);
        ns+=s[n-1];
        string s2=ns.substr(1,n);
         s2=sorted(s2);
        string s3=ns[0] + s2;
        if(s3==one) return 2;

          ns="";
          ns+=s[0];
          
          s1=s.substr(1,n);        
         ns=ns+sorted(s1);

        // cout << ns << endl;
         s2=ns.substr(0,n-1);
        
         s2=sorted(s2);
        // cout << s2 << endl;
         s3=s2+ns[n-1];
        if(s3==one) return 2;
        

        
        return 3;
        
    }
};