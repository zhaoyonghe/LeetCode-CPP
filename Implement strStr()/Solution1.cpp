// 8, 68.36

#include<string>

using namespace std;

class Solution1 {
public:
    int strStr(string haystack, string needle) {
        int end = haystack.length() - needle.length() + 1;

        for (int i = 0; i < end; i++) {
            bool isMatch = true;
            for (int j = 0; j < needle.length(); j++) {
                if (needle[j] != haystack[i + j]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return i;
            }
        }

        return -1;
    }
};