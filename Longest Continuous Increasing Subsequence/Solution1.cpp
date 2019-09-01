// 4, 100.00

#include<vector>

using namespace std;

class Solution1 {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int maxCount = 1;
        int count = 1;

        int i = 1;

        while (i < nums.size()) {
            if (nums[i] > nums[i - 1]) {
                count += 1;
                maxCount = max(maxCount, count);
                i += 1;
            } else {
                count = 1;
                i += 1;
            }
        }

        return maxCount;
    }
};