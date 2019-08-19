// 32, 94.14

#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permute(nums, 0, result);
        return result;
    }

    void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size() - 1) {
            vector<int> temp(nums);
            result.push_back(temp);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            bool isUnique = true;
            for (int j = start; j < i; j++) {
                if (nums[i] == nums[j]) {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique) {
                swap(nums, start, i);
                permute(nums, start + 1, result);
                swap(nums, start, i);
            }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};