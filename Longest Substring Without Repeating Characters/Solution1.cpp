// 8, 96.74

#include<string>

using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }

        int start = 0;
        int end = 0;
        int maxLen = 1;

        int a[128];

        for (int i = 0; i < 128; i++) {
            a[i] = -1;
        }

        while (end < s.length()) {
            if (a[s[end]] == -1) {
                a[s[end]] = end;
                int tempLen = end - start + 1;
                maxLen = maxLen < tempLen ? tempLen : maxLen;
                end += 1;
            } else {
                if (a[s[end]] >= start) {
                    start = a[s[end]] + 1;
                } else {
                    a[s[end]] = end;
                    int tempLen = end - start + 1;
                    maxLen = maxLen < tempLen ? tempLen : maxLen;
                    end += 1;
                }
            }
        }

        return maxLen;
    }
};