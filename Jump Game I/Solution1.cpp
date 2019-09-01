// 8, 98.47

#include<vector>

using namespace std;

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int frontier = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > frontier) {
                return false;
            }
            frontier = max(frontier, i + nums[i]);
            if (frontier >= nums.size() - 1) {
                return true;
            }
        }
        return true;
    }
};