class Solution {
public:
    double myPow(double x, int n) {
        double ans =1;
        double base = x;
        if(n==0)
            return ans;
        long long  mi;
        if(n>0)
            mi=n;
        else{
            mi = n;
            mi=-mi;
        }
        while(mi!=0)
        {
            if(mi&1)
            {
                ans =ans *base;
            }
            base=base*base;
            mi>>=1;
        }
        if(n>0)
            return ans;
        return 1.0/ans;
    }
};