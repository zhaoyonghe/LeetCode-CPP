// 4, 96.63

#include<vector>
#include<string>

using namespace std;

class Solution1 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		}

		string result = "";

		int i = 0;

		while (true) {
			char c;
			if (i == strs[0].length()) {
				break;
			} else {
				c = strs[0][i];
			}

			for (int j = 1; j < strs.size(); j++) {
				if (!(i < strs[j].length() && strs[j][i] == c)) {
					goto label;
				}
			}

			result += c;
			i += 1;
		}

label:
		return result;
	}
};