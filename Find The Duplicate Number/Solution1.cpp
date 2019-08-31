// 12, 89.19

#include<vector>

using namespace std;

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;

        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) {
                break;
            }
        }

        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};