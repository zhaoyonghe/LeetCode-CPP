// 4, 99.13

#include<climits>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        int i = 0;

        while (i < nums.size()) {
            curSum += nums[i];
            maxSum = curSum > maxSum ? curSum : maxSum;

            // meaningless to contain the previous part when curSum is less than 0
            curSum = curSum < 0 ? 0 : curSum;

            i += 1;
        }

        return maxSum;
    }
};