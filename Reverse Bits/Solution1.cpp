// 4, 86.46

#include<cstdint>

class Solution1 {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;

		for (int i = 0; i < 32; i++) {
			if ((n & (1 << i)) != 0) {
				result |= (1 << (31 - i));
			}
		}

		return result;
	}
};