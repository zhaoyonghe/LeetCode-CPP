// 20, 97.81

#include<vector>
#include<algorithm>

using namespace std;

class Solution1 {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> result;
        result.push_back({intervals[0][0], intervals[0][1]});

        int i = 1;

        while (i < intervals.size()) {
            if (result[result.size() - 1][1] < intervals[i][0]) {
                result.push_back(intervals[i]);
            } else {
                // result[result.size() - 1][1] >= intervals[i][0]
                // merge
                result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
            }
            i += 1;
        }

        return result;
    }
};