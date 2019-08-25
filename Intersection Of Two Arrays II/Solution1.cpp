// 

#include<vector>
#include<unordered_map>

using namespace std;

class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;

        for (int num : nums1) {
            auto it = map.find(num);
            if (it == map.end()) {
                map[num] = 1;
            } else {
                map[num] = it -> second + 1;
            }
        }

        vector<int> result;
        for (int num : nums2) {
            auto it = map.find(num);
            if (it != map.end()) {
                result.push_back(num);
                if (it -> second == 1) {
                    map.erase(num);
                } else {
                    map[num] = it -> second - 1;
                }
            }
        }

        return result;
    }
};