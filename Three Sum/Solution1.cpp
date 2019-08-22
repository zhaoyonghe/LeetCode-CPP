// 136, 93.40

#include<vector>
#include<algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        int lastVal = nums[0] == 0 ? -1 : 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == lastVal) {
                continue;
            }

            int start = i + 1;
            int end = nums.size() - 1;
            int target = -nums[i];

            while (start < end) {
                if (nums[start] + nums[end] < target) {
                    start += 1;
                } else if (nums[start] + nums[end] > target) {
                    end -= 1;
                } else {
                    result.push_back({nums[i], nums[start], nums[end]});
                    int val1 = nums[start];
                    while (start < end && nums[start] == val1) {
                        start += 1;
                    }
                    int val2 = nums[end];
                    while (start < end && nums[end] == val2) {
                        end -= 1;
                    }
                }
            }

            lastVal = nums[i];
        }

        return result;
    }
};