// 12, 90.80

#include<vector>
#include<algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        vector<vector<int>> result;

        subsetsWithDup(current, 0, nums, result);

        return result;

    }

    void subsetsWithDup(vector<int>& current, int i, vector<int>& nums, vector<vector<int>>& result) {
        if (i == nums.size()) {
            vector<int> temp(current);
            result.push_back(temp);
            return;
        }

        int j = i;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                break;
            }
            j += 1;
        }

        subsetsWithDup(current, j, nums, result);

        for (int k = i; k < j; k++) {
            current.push_back(nums[k]);
            subsetsWithDup(current, j, nums, result);
        }

        for (int k = i; k < j; k++) {
            current.pop_back();
        }
    }
};