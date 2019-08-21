// 20, 77.85
// O(n)

#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution2 {
public:
    long getBucketId(long num, long bucketWidth) {
        return num < 0 ? (num + 1) / bucketWidth - 1 : num / bucketWidth;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) {
            return false;
        }

        unordered_map<long, int> map;

        long bucketWidth = (long)t + 1;

        for (int i = 0; i < nums.size(); i++) {
            long id = getBucketId(nums[i], bucketWidth);

            if (map.find(id) != map.end()) {
                return true;
            }

            auto it1 = map.find(id - 1);
            if (it1 != map.end() && abs((long)nums[i] - (long)it1 -> second) <= (long)t) {
                return true;
            }

            auto it2 = map.find(id + 1);
            if (it2 != map.end() && abs((long)nums[i] - (long)it2 -> second) <= (long)t) {
                return true;
            }

            map[id] = nums[i];

            if (i >= k) {
                map.erase(getBucketId((long)nums[i - k], bucketWidth));
            }
        }

        return false;
    }
};