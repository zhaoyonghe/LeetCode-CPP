// 12, 99.64

#include<vector>

using namespace std;

class Solution1 {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;

		int maxArea = 0;

		while (left < right) {
			int h = height[left] < height[right] ? height[left] : height[right];
			int curArea = (right - left) * h;
			maxArea = maxArea < curArea ? curArea : maxArea;

			if (height[left] < height[right]) {
				left += 1;
			} else if (height[left] > height[right]) {
				right -= 1;
			} else {
				left += 1;
				right -= 1;
			}
		}

		return maxArea;
	}
};