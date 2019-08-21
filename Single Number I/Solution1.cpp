// 12, 97.66

#include<vector>

using namespace std;

class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;

		for (int i = 0; i < nums.size(); i++) {
			result = result ^ nums[i];
		}

		return result;
	}
};