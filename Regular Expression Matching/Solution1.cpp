// 0, 100.00

#include<string>

using namespace std;

class Solution1 {
public:
	bool isMatch(string s, string p) {
		int sLen = s.length();
		int pLen = p.length();

		bool dp[pLen + 1][sLen + 1];
		for (int i = 0; i <= pLen; i++) {
			for (int j = 0; j <= sLen; j++) {
				dp[i][j] = false;
			}
		}

		dp[0][0] = true;

		for (int i = 2; i <= pLen; i += 2) {
			if (p[i - 1] == '*') {
				dp[i][0] = true;
			} else {
				break;
			}
		}

		for (int i = 1; i <= pLen; i++) {
			for (int j = 1; j <= sLen; j++) {
				int pi = i - 1;
				int sj = j - 1;
				if (p[pi] == '.') {
					dp[i][j] = dp[i - 1][j - 1];
				} else if (p[pi] == '*') {
					dp[i][j] = dp[i - 2][j] || (dp[i][j - 1] && (p[pi - 1] == '.' || p[pi - 1] == s[sj]));
				} else {
					dp[i][j] = dp[i - 1][j - 1] && (p[pi] == s[sj]);
				}
			}
		}

		return dp[pLen][sLen];
	}
};