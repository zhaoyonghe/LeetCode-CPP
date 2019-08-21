// 12, 97.08

#include<vector>

using namespace std;

class Solution1 {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int div = 0;

		for (int i = 0; i < nums.size(); i++) {
			div ^= nums[i];
		}

		int i = 0;
		while (true) {
			if ((div | (1 << i)) == div) {
				break;
			}
			i += 1;
		}

		int divider = (1 << i);

		vector<int> result;
		result.push_back(0);
		result.push_back(0);

		for (int i = 0; i < nums.size(); i++) {
			if ((nums[i] | divider) == nums[i]) {
				result[0] ^= nums[i];
			} else {
				result[1] ^= nums[i];
			}
		}

		return result;
	}
};

