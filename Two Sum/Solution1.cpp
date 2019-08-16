#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map;
		std::vector<int> result;
		for (unsigned int i = 0; i < nums.size(); i++) {
			//cout << "fds" << endl;
			auto it = map.find(nums[i]);
			if (it == map.end()) {
				map[target - nums[i]] = i;
			} else {
				result.push_back(it->second);
				result.push_back(i);
				return result;
			}
		}
		return result;
	}
};

int main(int argc, char const* argv[]) {
	Solution s;

	std::vector<int> vv;
	vv.push_back(2);
	vv.push_back(7);
	vv.push_back(1);
	vv.push_back(9);

	std::vector<int> v = s.twoSum(vv, 9);

	std::cout << v[0] << " " << v[1] << std::endl;

	return 0;
}