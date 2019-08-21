// 32, 91.01

#include<vector>
#include<unordered_map>

using namespace std;

class Solution1 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(nums[i]);

            if (it == map.end()) {
                map[nums[i]] = i;
            } else {
                if (abs(i - it -> second) <= k) {
                    return true;
                } else {
                    map[nums[i]] = i;
                }
            }
        }

        return false;
    }
};