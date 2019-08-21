// 0, 100.00

class Solution1 {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) {
			return false;
		}

		return (n & (n - 1)) == 0;
	}
};