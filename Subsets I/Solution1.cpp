// 8, 90.25

#include<vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;

        subsets(current, 0, nums, result);

        return result;
    }

    void subsets(vector<int>& current, int i, vector<int>& nums, vector<vector<int>>& result) {
        if (i == nums.size()) {
            vector<int> temp(current);
            result.push_back(temp);
            return;
        }

        // no adding
        subsets(current, i + 1, nums, result);

        // add
        current.push_back(nums[i]);
        subsets(current, i + 1, nums, result);
        current.pop_back();
    }
};