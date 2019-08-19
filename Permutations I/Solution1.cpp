// 12, 98.79

#include<vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            swap(nums, start, i);
            permute(nums, start + 1, result);
            swap(nums, start, i);
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};