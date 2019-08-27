// 0, 100.00

#include<vector>
#include<climits>

using namespace std;

class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (get(nums, mid - 1) < get(nums, mid)) {
                if (get(nums, mid) < get(nums, mid + 1)) {
                    start = mid + 1;
                } else {
                    // get(nums, mid) > get(nums, mid + 1)
                    return mid;
                }
            } else {
                // get(nums, mid - 1) > get(nums, mid)
                end = mid - 1;
            }
        }

        return -1;
    }

    long get(vector<int>& nums, int i) {
        if (i == -1 || i == nums.size()) {
            return LONG_MIN;
        } else {
            return nums[i];
        }
    }
};