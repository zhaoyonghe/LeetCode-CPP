// 4, 80.30

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

        int a = rob(nums, 0, nums.size() - 2);
        int b = rob(nums, 1, nums.size() - 1);

        return a > b ? a : b;
    }

    int rob(vector<int>& nums, int start, int end) {
        int len = end - start + 1;

        int dp[len];

        dp[0] = nums[start];
        dp[1] = nums[start] > nums[start + 1] ? nums[start] : nums[start + 1];

        for (int i = 2; i < len; i++) {
            int a = dp[i - 2] + nums[start + i];
            int b = dp[i - 1];
            dp[i] = a > b ? a : b;
        }

        return dp[len - 1];
    }
};