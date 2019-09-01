// 8, 85.46

#include<vector>

using namespace std;

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> vec;

        vec.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > vec.back()) {
                vec.push_back(nums[i]);
            } else {
                vec[find(vec, nums[i])] = nums[i];
            }
        }

        return vec.size();
    }

    int find(vector<int>& vec, int num) {
        int start = 0;
        int end = vec.size() - 1;

        while (start < end) {
            int mid = (start + end) / 2;

            if (vec[mid] > num) {
                end = mid;
            } else if (vec[mid] < num) {
                start = mid + 1;
            } else {
                // vec[mid] == num
                return mid;
            }
        }

        return end;
    }
};