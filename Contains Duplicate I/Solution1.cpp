// 36, 90.09

#include<vector>
#include<unordered_set>

using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++) {
            auto it = set.find(nums[i]);

            if (it == set.end()) {
                set.emplace(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};