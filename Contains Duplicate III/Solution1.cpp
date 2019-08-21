// 16, 81.17
// O(n * min(k, 2t))

#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();

        if (k >= n) {
            k = n - 1;
        }

        if ((k >> 1) < t) {
            for (int i = 0; i < n; i++) {
                for (int j = i - k >= 0 ? i - k : 0; j < i; j++) {
                    if (abs((long)nums[i] - (long)nums[j]) <= t) {
                        return true;
                    }
                }
            }
        } else {
            unordered_map<long, int> map;

            for (int i = 0; i < n; i++) {
                long lower = (long)nums[i] - (long)t;
                long upper = (long)nums[i] + (long)t;

                for (long num = lower; num <= upper; num++) {
                    auto it = map.find(num);
                    if (it != map.end() && abs(i - it -> second) <= k) {
                        return true;
                    }
                    if (num == (long)nums[i]) {
                        map[num] = i;
                    }

                }
            }
        }

        return false;
    }
};