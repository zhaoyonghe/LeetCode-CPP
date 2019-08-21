// 0, 100.00

class Solution1 {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0) {
			return false;
		}

		return ((num & (num - 1)) == 0) && ((num | 0x55555555) == 0x55555555);
	}
};