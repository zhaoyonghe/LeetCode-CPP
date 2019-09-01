// 12, 87.86

#include<vector>

using namespace std;

class Solution1 {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        // i start from last frontier plus one
        int i = 1;
        int frontier = nums[0];
        int count = 1;

        if (frontier >= nums.size() - 1) {
            return count;
        }

        while (true) {
            int newFrontier = frontier;
            // traversal from last frontier to next frontier
            for (; i <= frontier; i++) {
                // calculate new frontier
                newFrontier = max(newFrontier, i + nums[i]);
            }
            // i == frontier

            count += 1;
            if (newFrontier >= nums.size() - 1) {
                return count;
            }

            // update the frontier
            frontier = newFrontier;
            //cout << frontier;
        }

        return -1;
    }
};