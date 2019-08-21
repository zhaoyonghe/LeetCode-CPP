// 16, 61.74

#include<vector>

using namespace std;

class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		int x1 = 0;
		int x0 = 0;

		for (int i = 0; i < nums.size(); i++) {
			x1 ^= (x0 & nums[i]);
			x0 ^= nums[i];

			int mask = ~ (x1 & x0);

			x1 &= mask;
			x0 &= mask;
		}

		return x0;
	}
};