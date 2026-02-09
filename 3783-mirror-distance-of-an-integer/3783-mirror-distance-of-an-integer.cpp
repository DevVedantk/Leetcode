class Solution {
public:
    int mirrorDistance(int n) {

        string s=to_string(n);
        reverse(s.begin(),s.end());
        int n2=stoi(s);
        cout << n2 << endl;
        return abs(n-n2);
    }
};