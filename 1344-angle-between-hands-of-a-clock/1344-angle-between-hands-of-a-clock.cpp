class Solution {
public:
    double angleClock(int h, int m) {
        double hr=(double)(h+(double)m/60);
        hr=hr*30.0;

         double min=(double)m*6.0;

         double ans=abs(min-hr);
         if(ans>=180) ans=360-ans;
         return ans;
    }
};