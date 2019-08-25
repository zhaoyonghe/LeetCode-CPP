// 8, 83.98

#include<vector>

using namespace std;

class Solution1 {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] > nums[start]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] < nums[start]) {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                // nums[mid] == nums[start] != target
                do {
                    start += 1;
                } while (start + 1 <= end && nums[start] == nums[start + 1]);
            }
        }

        return false;
    }
};