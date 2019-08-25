// 4, 74.85

class Solution1 {
public:
	int hammingDistance(int x, int y) {
		int a = x ^ y;

		int count = 0;
		for (int i = 0; i < 32; i++) {
			count = ((a & (1 << i)) == 0) ? count : count + 1;
		}

		return count;
	}
};