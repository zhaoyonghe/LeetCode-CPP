// 24, 92.23

#include<vector>

using namespace std;

class Solution1 {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int sum = (n * (n + 1)) / 2;

		for (int num : nums) {
			sum -= num;
		}

		return sum;
	}
};