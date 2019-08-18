// 4, 87.04

#include <vector>

using namespace std;

class Solution1 {
public:
	int reverse(int x) {
		if (x == 0 || x == -2147483648) {
			return 0;
		}

		bool isPos = (x > 0);

		if (!isPos) {
			x = -x;
		}

		vector<int> vec;

		while (x != 0) {
			vec.push_back(x % 10);
			x /= 10;
		}

		if (isOverflow(vec, isPos)) {
			return 0;
		} else {
			int result = 0;

			for (int i = 0; i < vec.size() - 1; i++) {
				result += vec[i];
				result *= 10;
			}
			result += vec[vec.size() - 1];

			if (!isPos) {
				result = -result;
			}

			return result;
		}

	}

	bool isOverflow(vector<int>& vec, bool isPos) {
		if (vec.size() != 10) {
			// no overflow
			return false;
		}

		int max[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};

		/*
		if(!isPos){
		    bool isMinusMax = true;
		    for(int i = 0; i < 9; i++){
		        if(max[i] != vec[i]){
		            isMinusMax = false;
		            break;
		        }
		    }
		    isMinusMax = (vec[9] == 8);
		    if(isMinusMax){
		        return false;
		    }
		}*/

		// must be less or equal than 2147483647
		bool isEqualSoFar = true;
		for (int i = 0; i < 10; i++) {
			if (vec[i] < max[i]) {
				return false;
			}
			if (vec[i] > max[i]) {
				return true;
			}
		}
		return true;
	}
};