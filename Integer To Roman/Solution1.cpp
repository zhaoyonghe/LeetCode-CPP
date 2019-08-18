// 8, 92.12

#include<string>

using namespace std;

class Solution1 {
public:
	string intToRoman(int num) {
		string a[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM"}
		};

		string result = "";

		int i = 0;

		while (num != 0) {
			int temp = num % 10;
			result = a[i][temp] + result;

			num /= 10;
			i += 1;
		}

		return result;
	}
};