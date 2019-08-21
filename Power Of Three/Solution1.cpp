// 20, 78.09

class Solution1 {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) {
			return false;
		}

		while (n >= 3 && n % 3 == 0) {
			n /= 3;
		}

		return n == 1;
	}
};