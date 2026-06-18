class Solution {
public:
    double angleClock(int h, int m) {
        double hr=(double)30*h;
         double min=(double)11*((double)m/2);

          double ans=abs(hr-min);
          if(ans>=(double)180) ans=(double)360-ans;  
         return ans;
    }
};