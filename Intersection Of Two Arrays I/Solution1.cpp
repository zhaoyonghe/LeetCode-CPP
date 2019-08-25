// 8, 96.45

#include<vector>
#include<unordered_set>

using namespace std;

class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;

        for (int num : nums1) {
            set.emplace(num);
        }

        vector<int> result;
        for (int num : nums2) {
            auto it = set.find(num);
            if (it != set.end()) {
                result.push_back(*it);
                set.erase(*it);
            }
        }

        return result;
    }
};