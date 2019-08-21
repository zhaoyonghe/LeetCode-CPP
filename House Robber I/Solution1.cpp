// 0, 100.00

#include<vector>

using namespace std;

class Solution1 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }

        int dp[nums.size()];

        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

        for (int i = 2; i < nums.size(); i++) {
            int a = dp[i - 2] + nums[i];
            int b = dp[i - 1];

            dp[i] = a > b ? a : b;
        }

        return dp[nums.size() - 1];
    }
};