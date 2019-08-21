// 40, 90.99

class Solution1 {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        bool a[n];

        for (int i = 0; i < n; i++) {
            a[i] = true;
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (a[i]) {
                count += 1;
                for (int j = i; j < n; j += i) {
                    a[j] = false;
                }
            }
        }

        return count;
    }
};