// 24, 97.66

#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int i = 0;
        int top = 0;

        while (i < nums.size()) {
            if (nums[i] != nums[top]) {
                top += 1;
                nums[top] = nums[i];
            }
            i += 1;
        }

        return top + 1;
    }
};