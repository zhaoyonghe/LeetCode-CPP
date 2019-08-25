// 4, 90.84

#include<vector>

using namespace std;

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                return mid;
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
                start += 1;
            }
        }

        return -1;
    }
};