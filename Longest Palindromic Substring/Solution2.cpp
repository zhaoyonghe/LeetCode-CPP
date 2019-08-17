// 24, 86.44

#include <string>

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }

        int start = 0;
        int end = 0;

        for (int i = 1; i < s.length(); i++) {
            findPalindrome(s, i, i, start, end);
            findPalindrome(s, i - 1, i, start, end);
        }

        return s.substr(start, end - start + 1);
    }

    void findPalindrome(string& s, int m1, int m2, int& start, int& end) {
        int low = m1;
        int high = m2;

        while (low > -1 && high < s.length() && s[low] == s[high]) {
            low -= 1;
            high += 1;
        }

        low += 1;
        high -= 1;

        if (end - start < high - low) {
            start = low;
            end = high;
        }
    }
};