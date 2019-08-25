// 12, 73.32

#include<vector>

using namespace std;

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec;
        vec.push_back(-1);
        vec.push_back(-1);

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                // nums[mid] == target
                if (mid > 0 && nums[mid - 1] == target) {
                    end = mid - 1;
                } else {
                    vec[0] = mid;
                    break;
                }
            }
        }

        if (vec[0] == -1) {
            return vec;
        }

        start = 0;
        end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                // nums[mid] == target
                if (mid < nums.size() - 1 && nums[mid + 1] == target) {
                    start = mid + 1;
                } else {
                    vec[1] = mid;
                    break;
                }
            }
        }

        return vec;
    }
};