// 4, 97.82

#include<vector>
#include<climits>

using namespace std;

class Solution1 {
public:
    bool increasingTriplet(vector<int>& nums) {
        long a = LONG_MAX;
        long b = LONG_MAX;

        for (int num : nums) {
            if ((long)num <= a) {
                a = num;
            } else if ((long)num > a && (long)num <= b) {
                b = num;
            } else {
                // num > b
                return true;
            }
        }

        return false;
    }
};