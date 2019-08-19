// 4, 83.11

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) {
            return 1;
        }

        long m = (long) n;

        if (m < 0) {
            x = 1 / x;
            m = -m;
        }

        double result = 1;
        double temp = x;
        while (m != 0) {
            if ((m & 1) != 0) {
                result *= temp;
            }
            temp *= temp;
            m = (m >> 1);
        }

        return result;
    }
};