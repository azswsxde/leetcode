class Solution {
public:
    double myPow(double x, int n) {
        long times = n;
        if (times < 0) {
            times = abs(times);
            x = 1/x;
        }

        double result = 1.0;
        while(times > 0){
            if (times % 2 == 1)
                result *= x;
            
            x = x * x;
            times /= 2 ;
        }
        return result;
    }
};