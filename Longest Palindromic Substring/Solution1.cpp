// 244, 33.39
// dynamic programming

#include <string>

using namespace std;

class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }

        int len = s.length();

        // dp[end][start]
        bool dp[len][len];

        for (int j = 0; j < len; j++) {
            for (int i = 0; i < len; i++) {
                dp[j][i] = false;
            }
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < len - 1; i++) {
            dp[i + 1][i] = (s[i] == s[i + 1]);
            if (dp[i + 1][i]) {
                start = i;
                end = i + 1;
            }
        }

        for (int j = 2; j < len; j++) {
            for (int i = 0; i < j - 1; i++) {
                dp[j][i] = (s[i] == s[j]) && dp[j - 1][i + 1];
                if (dp[j][i] && ((j - i) > (end - start))) {
                    start = i;
                    end = j;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};