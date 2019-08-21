// 4, 83.46

#include<cstdint>

class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) {
                count += 1;
            }
        }

        return count;
    }
};