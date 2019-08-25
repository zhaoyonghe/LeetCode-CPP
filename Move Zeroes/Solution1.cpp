// 16, 95.95

#include<vector>

using namespace std;

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int top = 0;

        while (i < nums.size()) {
            if (nums[i] != 0) {
                swap(nums, i, top);
                top += 1;
            }
            i += 1;
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};