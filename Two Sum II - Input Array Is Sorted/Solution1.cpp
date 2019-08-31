// 8, 80.90

#include<vector>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vec;

        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum > target) {
                j -= 1;
            } else if (sum < target) {
                i += 1;
            } else {
                // sum == target
                vec.push_back(i + 1);
                vec.push_back(j + 1);
                return vec;
            }
        }

        return vec;
    }
};