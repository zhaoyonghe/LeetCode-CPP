// 0, 100.00

class Solution1 {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }

        int a = 1;
        int b = 2;

        n -= 2;

        while (n > 0) {
            int temp = a + b;
            a = b;
            b = temp;
            n -= 1;
        }

        return b;
    }
};